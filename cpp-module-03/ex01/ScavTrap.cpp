#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
      std::cout << "ScavTrap " << name << " created(default)." << std::endl;
}

ScavTrap::ScavTrap(std::string name)  : ClapTrap(name)
{

    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    guardMode = false;
    std::cout << "ScavTrap " << name << " created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy)  : ClapTrap(copy)
{
    *this = copy;
    std::cout << "ScavTrap " << name << " copied." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& other)
{
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    std::cout << "ScavTrap " << name << " assigned." << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " destroyed." << std::endl;

}

void ScavTrap::attack(const std::string &target)
{
    if (hitPoints <= 0)
    {
        std::cout << "ScavTrap " << name << " cannot attack because it has no hit points!" << std::endl;
        return ;
    }

    if (energyPoints <= 0)
    {
        std::cout << "ScavTrap " << name << " cannot repair because it has no energy points!" << std::endl;
        return ;
    }
    energyPoints--;
    if (guardMode == true)
        std::cout << "ScavTrap [" << name << "] attacks [" << target 
        << "] fiercely in Gate Guard mode, causing [" 
        << attackDamage << "] points of damage!" << std::endl;
    else
        std::cout << "ScavTrap [" << name << "] attacks [" << target << "] causing [" 
              << attackDamage << "] points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    guardMode = true;
    std::cout << "ScavTrap " << name << " is now in Gate Guard mode!" << std::endl;
}