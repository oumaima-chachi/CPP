#ifndef Fixed_hpp
#define Fixed_hpp

#include <iostream>

class Fixed {
    private:
        int value;
        static const int fractional_bits = 8;
    
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator+(const Fixed& other);
        ~Fixed();


        int  getRawBits(void) const;
        void setRawBits(int const raw);

 

}; 
#endif