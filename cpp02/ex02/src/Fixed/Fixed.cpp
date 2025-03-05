#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point_value = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point_value = num << this->fractional_bits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point_value = roundf(num * (1 << this->fractional_bits));
}

float	Fixed::toFloat(void) const
{
	return this->fixed_point_value / ((float) (1 << this->fractional_bits));
}

int	Fixed::toInt(void) const
{
	return this->fixed_point_value >> this->fractional_bits;
}

int	Fixed::getRawBits(void) const
{
	return this->fixed_point_value;
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point_value = raw;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &fixed)
	{
		return *this;
	}
	this->fixed_point_value = fixed.getRawBits();
	return *this;
}

bool	Fixed::operator>(const Fixed &fixed)
{
	return this->fixed_point_value > fixed.fixed_point_value;
}

bool	Fixed::operator<(const Fixed &fixed)
{
	return this->fixed_point_value < fixed.fixed_point_value;
}

bool	Fixed::operator>=(const Fixed &fixed)
{
	return this->fixed_point_value >= fixed.fixed_point_value;
}

bool	Fixed::operator<=(const Fixed &fixed)
{
	return this->fixed_point_value <= fixed.fixed_point_value;
}

bool	Fixed::operator==(const Fixed &fixed)
{
	return this->fixed_point_value == fixed.fixed_point_value;
}

bool	Fixed::operator!=(const Fixed &fixed)
{
	return this->fixed_point_value != fixed.fixed_point_value;
}

Fixed	Fixed::operator+(const Fixed &fixed)
{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed	Fixed::operator-(const Fixed &fixed)
{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed	Fixed::operator*(const Fixed &fixed)
{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator/(const Fixed &fixed)
{
	return Fixed(this->toFloat() / fixed.toFloat());
}

std::ostream	&operator<<(std::ostream &stream, const Fixed &fixed)
{
	stream << fixed.toFloat();
	return stream;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
