#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	this->fixed_point_value = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed::Fixed(const int num)
{
	this->fixed_point_value = num << this->fractional_bits;
}

Fixed::Fixed(const float num)
{
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

Fixed	&Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2) return f1;

	return f2;
}

const Fixed	&Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 < f2) return f1;

	return f2;
}

Fixed	&Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 > f2) return f1;

	return f2;
}

const Fixed	&Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1 > f2) return f1;

	return f2;
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point_value = raw;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	if (this == &fixed)
	{
		return *this;
	}
	this->setRawBits(fixed.getRawBits());
	return *this;
}

bool	Fixed::operator>(const Fixed &fixed) const
{
	return this->fixed_point_value > fixed.fixed_point_value;
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return this->fixed_point_value < fixed.fixed_point_value;
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return this->fixed_point_value >= fixed.fixed_point_value;
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return this->fixed_point_value <= fixed.fixed_point_value;
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return this->fixed_point_value == fixed.fixed_point_value;
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return this->fixed_point_value != fixed.fixed_point_value;
}

Fixed	Fixed::operator+(const Fixed &fixed) const
{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed	Fixed::operator-(const Fixed &fixed) const
{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed	Fixed::operator*(const Fixed &fixed) const
{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator/(const Fixed &fixed) const
{
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed	&Fixed::operator++(void)
{
	this->fixed_point_value++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;

	this->fixed_point_value++;
	return temp;
}

Fixed	&Fixed::operator--(void)
{
	this->fixed_point_value--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;

	this->fixed_point_value--;
	return temp;
}

std::ostream	&operator<<(std::ostream &stream, const Fixed &fixed)
{
	stream << fixed.toFloat();
	return stream;
}

Fixed::~Fixed()
{
}
