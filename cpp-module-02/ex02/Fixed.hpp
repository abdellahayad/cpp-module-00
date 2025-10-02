#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
    private:
        int fixdVal;
        static const int fracBits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &other);
        Fixed(const float f);
        Fixed(const int n);
        Fixed &operator=(const Fixed &other);

        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const; 

        // The 6 comparison operators: >, <, >=, <=, ==, and !=.
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other)const;
        bool operator>=(const Fixed& other)const;
        bool operator<=(const Fixed& other)const;
        bool operator==(const Fixed& other)const;
        bool operator!=(const Fixed& other)const;

        //  The 4 arithmetic operators: +, -, *, and /.
        float operator+(const Fixed& other) const;
        float operator-(const Fixed& other) const;
        float operator*(Fixed other) const;
        float operator/(Fixed other) const;
        
        // The 4 increment/decrement
        Fixed &operator++();
        Fixed &operator--();
        Fixed operator++(int);
        Fixed operator--(int);

        // min, max
        static  Fixed& min(Fixed &a, Fixed &b);
        static  const Fixed& min(const Fixed &a, const Fixed &b);
        static  Fixed& max(Fixed &a, Fixed &b);
        static  const Fixed& max(const Fixed &a, const Fixed &b);

};

std::ostream &operator<<(std::ostream &os, const Fixed &f);


#endif