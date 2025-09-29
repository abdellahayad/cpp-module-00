#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
    private:
        int value;
    public:
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other)const;
        bool operator>=(const Fixed& other)const;
        bool operator<=(const Fixed& other)const;
        bool operator==(const Fixed& other)const;
        bool operator!=(const Fixed& other)const;

        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        
};


#endif