#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointValue(0)
{
}

Fixed::Fixed(Fixed const & copy)
{
	*this = copy;
}

Fixed::~Fixed()
{
}

Fixed & Fixed::operator=(Fixed const & copy)
{
	this->_fixedPointValue = copy.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	return this->_fixedPointValue;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

Fixed::Fixed(const int value)
{
	this->_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	this->_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

float Fixed::toFloat(void) const
{
	return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return this->_fixedPointValue >> Fixed::_fractionalBits;
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	if (a < b)
		return a;
	return b;
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed & Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed & Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a > b)
		return a;
	return b;
}

std::ostream & operator<<(std::ostream & out, Fixed const & value)
{
	out << value.toFloat();
	return out;
}

bool Fixed::operator>(Fixed const & value) const
{
	return this->_fixedPointValue > value._fixedPointValue;
}

bool Fixed::operator<(Fixed const & value) const
{
	return this->_fixedPointValue < value._fixedPointValue;
}

bool Fixed::operator>=(Fixed const & value) const
{
	return this->_fixedPointValue >= value._fixedPointValue;
}

bool Fixed::operator<=(Fixed const & value) const
{
	return this->_fixedPointValue <= value._fixedPointValue;
}

bool Fixed::operator==(Fixed const & value) const
{
	return this->_fixedPointValue == value._fixedPointValue;
}

bool Fixed::operator!=(Fixed const & value) const
{
	return this->_fixedPointValue != value._fixedPointValue;
}

Fixed Fixed::operator+(Fixed const & value) const
{
	return Fixed(this->toFloat() + value.toFloat());
}

Fixed Fixed::operator-(Fixed const & value) const
{
	return Fixed(this->toFloat() - value.toFloat());
}

Fixed Fixed::operator*(Fixed const & value) const
{
	return Fixed(this->toFloat() * value.toFloat());
}

Fixed Fixed::operator/(Fixed const & value) const
{
	return Fixed(this->toFloat() / value.toFloat());
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->_fixedPointValue++;
	return tmp;
}

Fixed & Fixed::operator++(void)
{
	this->_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->_fixedPointValue--;
	return tmp;
}

Fixed & Fixed::operator--(void)
{
	this->_fixedPointValue--;
	return *this;
}
