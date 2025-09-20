#include "Zombie.hpp"

int main()
{
    int N = 8;

    Zombie* horde = zombieHorde(N, "Foo");
    for (int i = 0; i < N; i++)
        horde[i].annonce();
    
    delete[] horde;
    
    return (0);
}