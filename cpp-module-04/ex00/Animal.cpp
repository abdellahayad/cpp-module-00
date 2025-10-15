#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal created." << std::endl;
}

Animal::Animal(const Animal& copy) : type(copy.type){}

Animal &Animal::operator=(const Animal& other)
{
    if (this != &other)
        type = other.type;
    
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal Destroyed." << std::endl;
}

std::string Animal::getType() const
{
    return (type);
}

void Animal::makeSound() const
{
    std::cout << "Generic sound animal." << std::endl;
}
