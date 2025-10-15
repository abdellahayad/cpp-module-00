#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << "AAnimal created." << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy) : type(copy.type){}

AAnimal &AAnimal::operator=(const AAnimal& other)
{
    if (this != &other)
        type = other.type;
    
    return (*this);
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal Destroyed." << std::endl;
}

std::string AAnimal::getType() const
{
    return (type);
}
