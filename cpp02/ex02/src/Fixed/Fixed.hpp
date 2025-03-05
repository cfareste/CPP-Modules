#pragma once

#include <fstream>

class Fixed {
	private:
		int					fixed_point_value;
		static const int	fractional_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int num);
		Fixed(const float num);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		Fixed	&operator=(const Fixed &fixed);
		bool	operator>(const Fixed &fixed);
		bool	operator<(const Fixed &fixed);
		bool	operator>=(const Fixed &fixed);
		bool	operator<=(const Fixed &fixed);
		bool	operator==(const Fixed &fixed);
		bool	operator!=(const Fixed &fixed);
		Fixed	operator+(const Fixed &fixed);
		Fixed	operator-(const Fixed &fixed);
		Fixed	operator*(const Fixed &fixed);
		Fixed	operator/(const Fixed &fixed);

		~Fixed();
};

std::ostream	&operator<<(std::ostream &stream, const Fixed &fixed);
