#include "Dog.hpp"


Dog::Dog()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog created." << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
    type = copy.type;
    brain = new Brain(*copy.brain);
}

Dog &Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        type = other.type;
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog Destroyed." << std::endl;
}
void Dog::makeSound() const
{
    std::cout << "Hoow!, HOOW!" << std::endl;
}

Brain* Dog::getBrain() const
{
    return brain;
}