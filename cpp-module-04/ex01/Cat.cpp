#include "Cat.hpp"


Cat::Cat()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat created." << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
    type = copy.type;
    brain = new Brain(*copy.brain);
}

Cat &Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        type = other.type;
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat Destroyed." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow!, MEOW!" << std::endl;
}