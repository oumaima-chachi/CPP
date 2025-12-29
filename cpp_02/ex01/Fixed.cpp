#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int int_value)
{
    std::cout << "Int constructor called" << std::endl;
    value = int_value << fractional_bits;
}

Fixed::Fixed(const float float_value)
{
    std::cout << "Float constructor called" << std::endl;
    value = roundf(float_value * (1 << fractional_bits));
}

Fixed ::Fixed(const Fixed &other)
{
    std::cout << "copy constructor called" << std::endl;
    value = other.value;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &other)
    {
        value = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(value) / (1 << fractional_bits);
}  

int Fixed::toInt(void) const
{
    return value >> fractional_bits;
}           

int Fixed::getRawBits(void) const
{
    return value;
}       

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

