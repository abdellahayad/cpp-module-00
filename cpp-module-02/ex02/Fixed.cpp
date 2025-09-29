#include "Fixed.hpp"

bool Fixed::operator>(const Fixed& other) const
{
    return (this->value > other.value);
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->value < other.value);
}

bool Fixed::operator>=(const Fixed& other)const
{
    return (this->value >= other.value);
}

bool Fixed::operator<=(const Fixed& other)const
{
    return (this->value <= other.value);
}

bool Fixed::operator==(const Fixed& other)const
{
    return (this->value == other.value);
}

bool Fixed::operator!=(const Fixed& other)const
{
    return (this->value != other.value);
}
