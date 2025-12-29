#include "Fixed.hpp"
#include <cmath>

/* Constructors / Destructor */

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int int_value)
{
	value = int_value << Fractional_bits;
}

Fixed::Fixed(const float float_value)
{
	value = roundf(float_value * (1 << Fractional_bits));
}

Fixed::Fixed(const Fixed &other)
{
	value = other.value;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		value = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {}

/* Getters / Setters */

int Fixed::getRawBits(void) const
{
	return value;
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

/* Conversions */

float Fixed::toFloat(void) const
{
	return static_cast<float>(value) / (1 << Fractional_bits);
}

int Fixed::toInt(void) const
{
	return value >> Fractional_bits;
}

/* Comparison operators */

bool Fixed::operator>(const Fixed &other) const
{
	return value > other.value;
}

bool Fixed::operator<(const Fixed &other) const
{
	return value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const
{
	return value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return value != other.value;
}

/* Arithmetic operators */

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

/* Increment / Decrement */

Fixed& Fixed::operator++()
{
	++value;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	value++;
	return temp;
}

Fixed& Fixed::operator--()
{
	--value;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	value--;
	return temp;
}

/* Min / Max */

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

/* Stream operator */

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
