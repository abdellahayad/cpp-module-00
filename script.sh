#!/bin/bash

# Server Statistics Script
# Analyzes basic server performance metrics

# Color codes for better readability
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Function to print section headers
print_header() {
    echo -e "\n${BLUE}================================${NC}"
    echo -e "${BLUE}$1${NC}"
    echo -e "${BLUE}================================${NC}"
}

# Function to print subheaders
print_subheader() {
    echo -e "\n${GREEN}$1${NC}"
}

# Clear screen for better presentation
clear

echo -e "${YELLOW}╔════════════════════════════════════════╗${NC}"
echo -e "${YELLOW}║     SERVER PERFORMANCE STATISTICS      ║${NC}"
echo -e "${YELLOW}╚════════════════════════════════════════╝${NC}\n"

# System Information
print_header "SYSTEM INFORMATION"

# OS Version
print_subheader "OS Version:"
if [ -f /etc/os-release ]; then
    . /etc/os-release
    echo "  $PRETTY_NAME"
else
    echo "  $(uname -s) $(uname -r)"
fi

# Hostname
print_subheader "Hostname:"
echo "  $(hostname)"

# Uptime
print_subheader "System Uptime:"
uptime -p 2>/dev/null || uptime | awk '{print "  " $3 " " $4}'

# Load Average
print_subheader "Load Average (1m, 5m, 15m):"
echo "  $(uptime | awk -F'load average:' '{print $2}')"

# CPU Information
print_header "CPU STATISTICS"

# Total CPU Usage
print_subheader "Total CPU Usage:"
cpu_usage=$(top -bn1 | grep "Cpu(s)" | awk '{print $2}' | cut -d'%' -f1)
cpu_idle=$(top -bn1 | grep "Cpu(s)" | awk '{print $8}' | cut -d'%' -f1)
cpu_used=$(echo "100 - $cpu_idle" | bc)
echo "  Used: ${cpu_used}%"
echo "  Idle: ${cpu_idle}%"

# CPU Cores
print_subheader "CPU Cores:"
echo "  $(nproc) cores"

# Memory Statistics
print_header "MEMORY STATISTICS"

print_subheader "RAM Usage:"
memory_info=$(free -h | grep Mem)
total_mem=$(echo $memory_info | awk '{print $2}')
used_mem=$(echo $memory_info | awk '{print $3}')
free_mem=$(echo $memory_info | awk '{print $4}')
available_mem=$(echo $memory_info | awk '{print $7}')

# Calculate percentage
total_mem_kb=$(free | grep Mem | awk '{print $2}')
used_mem_kb=$(free | grep Mem | awk '{print $3}')
mem_percentage=$(awk "BEGIN {printf \"%.2f\", ($used_mem_kb/$total_mem_kb)*100}")

echo "  Total:     $total_mem"
echo "  Used:      $used_mem (${mem_percentage}%)"
echo "  Free:      $free_mem"
echo "  Available: $available_mem"

# Swap Usage
print_subheader "Swap Usage:"
swap_info=$(free -h | grep Swap)
total_swap=$(echo $swap_info | awk '{print $2}')
used_swap=$(echo $swap_info | awk '{print $3}')
free_swap=$(echo $swap_info | awk '{print $4}')

if [ "$total_swap" != "0B" ]; then
    total_swap_kb=$(free | grep Swap | awk '{print $2}')
    used_swap_kb=$(free | grep Swap | awk '{print $3}')
    if [ "$total_swap_kb" -gt 0 ]; then
        swap_percentage=$(awk "BEGIN {printf \"%.2f\", ($used_swap_kb/$total_swap_kb)*100}")
    else
        swap_percentage="0.00"
    fi
    echo "  Total: $total_swap"
    echo "  Used:  $used_swap (${swap_percentage}%)"
    echo "  Free:  $free_swap"
else
    echo "  No swap configured"
fi

# Disk Usage
print_header "DISK STATISTICS"

print_subheader "Disk Usage by Partition:"
df -h | grep -E '^/dev/' | awk '{printf "  %-20s Total: %-8s Used: %-8s Free: %-8s Usage: %s\n", $1, $2, $3, $4, $5}'

# Overall root partition
print_subheader "Root Partition (/):"
root_info=$(df -h / | tail -1)
echo "  Total: $(echo $root_info | awk '{print $2}')"
echo "  Used:  $(echo $root_info | awk '{print $3}') ($(echo $root_info | awk '{print $5}'))"
echo "  Free:  $(echo $root_info | awk '{print $4}')"

# Top 5 Processes by CPU
print_header "TOP 5 PROCESSES BY CPU USAGE"
echo ""
printf "  %-8s %-8s %-8s %-s\n" "PID" "USER" "CPU%" "COMMAND"
echo "  ───────────────────────────────────────────────────────────"
ps aux --sort=-%cpu | head -6 | tail -5 | awk '{printf "  %-8s %-8s %-8s %-s\n", $2, $1, $3, $11}'

# Top 5 Processes by Memory
print_header "TOP 5 PROCESSES BY MEMORY USAGE"
echo ""
printf "  %-8s %-8s %-8s %-s\n" "PID" "USER" "MEM%" "COMMAND"
echo "  ───────────────────────────────────────────────────────────"
ps aux --sort=-%mem | head -6 | tail -5 | awk '{printf "  %-8s %-8s %-8s %-s\n", $2, $1, $4, $11}'

# Logged in Users
print_header "USER INFORMATION"

print_subheader "Currently Logged In Users:"
who_output=$(who | wc -l)
if [ "$who_output" -gt 0 ]; then
    who | awk '{printf "  %-12s %-12s %s\n", $1, $2, $3" "$4}'
else
    echo "  No users currently logged in"
fi

# Failed Login Attempts (last 10)
print_subheader "Recent Failed Login Attempts:"
if [ -f /var/log/auth.log ]; then
    failed_logins=$(grep "Failed password" /var/log/auth.log 2>/dev/null | tail -10 | wc -l)
    echo "  Last 10 failed attempts: $failed_logins"
    if [ "$failed_logins" -gt 0 ]; then
        grep "Failed password" /var/log/auth.log 2>/dev/null | tail -5 | awk '{print "    " $1" "$2" "$3" - "$9" from "$11}'
    fi
elif [ -f /var/log/secure ]; then
    failed_logins=$(grep "Failed password" /var/log/secure 2>/dev/null | tail -10 | wc -l)
    echo "  Last 10 failed attempts: $failed_logins"
    if [ "$failed_logins" -gt 0 ]; then
        grep "Failed password" /var/log/secure 2>/dev/null | tail -5 | awk '{print "    " $1" "$2" "$3" - "$9" from "$11}'
    fi
else
    echo "  Unable to read authentication logs (requires sudo)"
fi

# Network Statistics
print_header "NETWORK STATISTICS"

print_subheader "Active Network Interfaces:"
ip -brief addr 2>/dev/null | grep UP | awk '{printf "  %-12s %s\n", $1, $3}' || ifconfig | grep -E "^[a-z]" | awk '{print "  " $1}'

print_subheader "Network Connections:"
echo "  Established: $(ss -tan 2>/dev/null | grep ESTAB | wc -l || netstat -tan 2>/dev/null | grep ESTABLISHED | wc -l)"
echo "  Listening:   $(ss -tln 2>/dev/null | grep LISTEN | wc -l || netstat -tln 2>/dev/null | grep LISTEN | wc -l)"

echo -e "${YELLOW}╔════════════════════════════════════════════════════════╗${NC}"
echo -e "${YELLOW}║     Report generated: $(date '+%Y-%m-%d %H:%M:%S')              ║${NC}"
echo -e "${YELLOW}╚════════════════════════════════════════════════════════╝${NC}\n"
