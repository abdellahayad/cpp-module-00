#include "Fixed.hpp"

// Default
Fixed::Fixed() : fixdVal(0) {}

// int constructor
Fixed::Fixed(const int n) { fixdVal = n << fracBits; }

// float constructor
Fixed::Fixed(const float f) { fixdVal = roundf(f * (1 << fracBits)); }

// copy
Fixed::Fixed(const Fixed& other) { fixdVal = other.fixdVal; }

// assign
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) fixdVal = other.fixdVal;
    return *this;
}

// destructor
Fixed::~Fixed() {}

// fixed → float
float Fixed::toFloat() const
{
     return fixdVal / (float)(1 << fracBits); 
}

// fixed → int
int Fixed::toInt() const { return fixdVal >> fracBits; }

// operator <<
std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    os << f.toFloat();
    return os;
}
