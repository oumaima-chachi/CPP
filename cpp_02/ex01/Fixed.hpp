#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>


class Fixed
{
    private:
        int                 value;
        static const int    fractional_bits = 8;
    
    public:    
        Fixed();
        Fixed(const Fixed &other);
        Fixed& operator=(const Fixed &other);
        ~Fixed();

        Fixed(int const int_value);
        Fixed(float const float_value);
    
        float toFloat(void) const;
        int toInt(void) const;
    
        int  getRawBits(void) const;
        void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif 