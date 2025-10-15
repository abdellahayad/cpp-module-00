#include "Brain.hpp"


Brain::Brain()
{
    std::cout << "Brain created." << std::endl;
}

Brain::Brain(const Brain& copy)
{
    for (int i = 0; i < 100; i++)
        ideas[i] = copy.ideas[i];
}
Brain &Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destroyed." << std::endl;
}


void Brain::setIdea(int i, const std::string& idea)
{
    if (i >= 0 && i < 100)
        ideas[i] = idea;
}

std::string Brain::getIdea(int i) const
{
    if (i >= 0 && i < 100)
        return ideas[i];
    return "????";
}