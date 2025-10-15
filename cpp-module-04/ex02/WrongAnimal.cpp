#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal() : type("wrongAnimal")
{
    std::cout << "WrongAnimal created." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
    type = copy.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
        type = other.type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destroyed." << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Generic sound wrongAnimal." << std::endl;
}