#include "Dog.hpp"


Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog created." << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
    type = copy.type;
}

Dog &Dog::operator=(const Dog& other)
{
    if (this != &other)
        type = other.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destroyed." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Hoow!, HOOW!" << std::endl;
}