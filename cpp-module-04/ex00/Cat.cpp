#include "Cat.hpp"


Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat created." << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
    type = copy.type;
}

Cat &Cat::operator=(const Cat& other)
{
    if (this != &other)
        type = other.type;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Destroyed." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow!, MEOW!" << std::endl;
}