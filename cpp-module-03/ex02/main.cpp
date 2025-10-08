#include "FragTrap.hpp"

int main()
{
    FragTrap g;
    FragTrap a("abdellah");
    a.attack("yassine");
    a.beRepaired(10);
    a.attack("hafid");
    a.takeDamage(30);
    a.beRepaired(10);

    return 0;
}
