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
		static Fixed	&min(Fixed &f1, Fixed &f2);
		static const Fixed	&min(const Fixed &f1, const Fixed &f2);
		static Fixed	&max(Fixed &f1, Fixed &f2);
		static const Fixed	&max(const Fixed &f1, const Fixed &f2);

		Fixed	&operator=(const Fixed &fixed);
		bool	operator>(const Fixed &fixed) const;
		bool	operator<(const Fixed &fixed) const;
		bool	operator>=(const Fixed &fixed) const;
		bool	operator<=(const Fixed &fixed) const;
		bool	operator==(const Fixed &fixed) const;
		bool	operator!=(const Fixed &fixed) const;
		Fixed	operator+(const Fixed &fixed) const;
		Fixed	operator-(const Fixed &fixed) const;
		Fixed	operator*(const Fixed &fixed) const;
		Fixed	operator/(const Fixed &fixed) const;
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		~Fixed();
};

std::ostream	&operator<<(std::ostream &stream, const Fixed &fixed);
