#pragma once

class Fixed {
	private:
		int					fixed_point_value;
		static const int	fractional_bits = 8;

	public:
		Fixed();
		Fixed(Fixed &fixed);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed & operator=(Fixed &fixed);

		~Fixed();
};
