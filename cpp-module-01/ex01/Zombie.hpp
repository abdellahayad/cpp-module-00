#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie{
    private:
        std::string name;
    public:
        Zombie();
        ~Zombie();
        void annonce(void);
        void setName(std::string newNmae);
};

Zombie* zombieHorde( int N, std::string name );

#endif