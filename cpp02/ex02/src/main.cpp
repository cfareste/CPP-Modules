#include "Fixed/Fixed.hpp"
#include <iostream>

int	main(void)
{
	Fixed		a;
	const Fixed	b = Fixed(Fixed(5.05f) * Fixed(2));
	Fixed		c = b;
	Fixed		d = Fixed(23.32f);

	std::cout << ((a < b) ? "true" : "false") << std::endl;
	std::cout << ((a > b) ? "true" : "false") << std::endl;
	std::cout << ((b <= c) ? "true" : "false") << std::endl;
	std::cout << ((b >= a) ? "true" : "false") << std::endl;
	std::cout << ((b == c) ? "true" : "false") << std::endl;
	std::cout << ((b != c) ? "true" : "false") << std::endl;

	std::cout << c + d << std::endl;
	std::cout << c - d << std::endl;
	std::cout << c * d << std::endl;
	std::cout << c / d << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;

	return 0;
}
