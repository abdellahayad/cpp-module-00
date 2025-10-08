#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Unknown"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " created(default)." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
    *this = copy;
    std::cout << "ClapTrap " << name << " copied." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap " << name << " assigned." << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " cannot attack because it has no hit points!" << std::endl;
        return ;
    }

    if (energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " cannot repair because it has no energy points!" << std::endl;
        return ;
    }
    energyPoints--;
    std::cout << "ClapTrap [" << name << "] attacks [" << target << "] causing [" 
        << attackDamage << "] points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << "cannot take more damge, it's already down!" << std::endl;
        return ;
    }

     if (amount >= hitPoints)
        hitPoints = 0;
    else
        hitPoints -= amount;

    std::cout << "ClapTrap " << name << " took " << amount << " points of damage! [HP: "
                << hitPoints << "]" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " is broken and can't repair itself!" << std::endl;
        return ;
    }
    else if (hitPoints <= 0)
    {
		std::cout << "ClapTrap " << this->name << " it's dead!" << std::endl;
		return;
    }
    hitPoints += amount;
    energyPoints--;
    std::cout << "ClapTrap " << name << " repais itself for " << (int)amount << " points! [HP: " << hitPoints
    << ", Energy: " << energyPoints << "]" << std::endl;
}