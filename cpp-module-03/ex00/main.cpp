#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("clap1");
    ClapTrap b("clap2");

    a.attack("abdellah");
    a.beRepaired(1);
    a.attack("yassine");

    ClapTrap c(a);

    a.attack("");

    return 0;
}
