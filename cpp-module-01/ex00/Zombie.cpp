#include "Zombie.hpp"

Zombie::Zombie(std::string name) :name(name){}

Zombie::~Zombie(void)
{
    std::cout << name << " is destroyed" << std::endl;
}
void Zombie::annonce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
