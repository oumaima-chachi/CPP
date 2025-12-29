#include "Fixed.hpp"

Fixed::Fixed():value(8)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other):value(other.value)
{
    std::cout << "copy constructor called" << std:: endl;
}

Fixed& Fixed::operator+(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    
    if (this != &other)
        value += other.value;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits(int const raw) {
    value = raw;
}
