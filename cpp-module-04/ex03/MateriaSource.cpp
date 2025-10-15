#include "MateriaSource.hpp"


MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        learned[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
    for (int i = 0; i < 4; i++)
    {
        if (copy.learned[i])
            learned[i] = copy.learned[i]->clone();
        else
            learned[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (learned[i])
            {
                delete learned[i];
                learned[i] = NULL;
            }
            if (other.learned[i])
                learned[i] = other.learned[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (learned[i])
            delete learned[i];
    }
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (!learned[i])
        {
            learned[i] = m->clone();
            return ;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (learned[i] && learned[i]->getType() == type)
            return (learned[i]->clone());
    }
    return NULL;
}