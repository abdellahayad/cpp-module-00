
#include "replace.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    Replace r(av[1], av[2], av[3]);

    if (!r.proccess())
        return (1);

    return (0);
}