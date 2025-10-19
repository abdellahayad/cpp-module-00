#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("Unknown") {}

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::AMateria(const AMateria& copy) : type(copy.type) {}

AMateria &AMateria::operator=(const AMateria& other)
{
    if (this != &other)
        type = other.type;
    return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const {return type;}

void AMateria::use(ICharacter &target)
{
    std::cout << " use generic materia on " << target.getName() << " *" << std::endl;
}