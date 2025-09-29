#include "Fixed.hpp"

Fixed::Fixed() : fixdVal(0)
{
    std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    fixdVal = other.fixdVal;
}
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    fixdVal = other.fixdVal;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const int n) 
{
    fixdVal = n << fracBits;
}

Fixed::Fixed(const float f)
{
    
    fixdVal = roundf(f * (1 <<  fracBits));
}

int Fixed::toInt() const
{
    return (fixdVal >> fracBits);
}

float Fixed::toFloat() const
{
    return (fixdVal / (float)(1 << fracBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
    os << f.toFloat();
    return os;
}
