#include "Zombie.hpp"

int main()
{
    Zombie* heapZombie = newZombie("Foo");
    heapZombie->annonce();
    delete heapZombie;

    randomChump("Bar");

    return (0);
}