#include "Fixed/Fixed.hpp"
#include "Point/Point.hpp"
#include <iostream>

#define WIDTH	40
#define HEIGHT	20

bool	bsp(Point const a, Point const b, Point const c, Point const p);

void	draw_triangle( const Point a, const Point b, const Point c, const Point p )
{
	for ( int i = -HEIGHT / 2; i <= HEIGHT / 2; i++ )
	{
		for ( int j = -WIDTH / 2; j <= WIDTH / 2; j++ )
		{
			Point	coord(i, j);
			if (coord == a)
				std::cout << "a";
			else if (coord == b)
				std::cout << "b";
			else if (coord == c)
				std::cout << "c";
			else if (coord == p)
				std::cout << "p";
			else
				std::cout << ".";
		}
		std::cout << std::endl;
	}
}

void	check_point_triangle( Point a, Point b, Point c, Point p )
{
	std::cout << "Point a: " << a << std::endl;
	std::cout << "Point b: " << b << std::endl;
	std::cout << "Point c: " << c << std::endl;
	std::cout << "Point p: " << p << std::endl;
	std::cout << "Is inside: " << (bsp(a, b, c, p) ? "true" : "false") << std::endl;
	draw_triangle(a, b, c, p);
}

int	main( void )
{
	check_point_triangle(Point(0, 0), Point(5, 0), Point(0, 5), Point(2, 2));
	std::cout << std::endl;
	check_point_triangle(Point(-5, 0), Point(5, 2), Point(2, -5), Point(-2, 0));
	std::cout << std::endl;
	check_point_triangle(Point(-7, 4), Point(4, -1), Point(-2, 6), Point(4, 2));
	std::cout << std::endl;
	check_point_triangle(Point(0, 0), Point(5, 0), Point(0, 5), Point(2.5, 2.5));
	std::cout << std::endl;
	check_point_triangle(Point(0, 0), Point(5, 0), Point(0, 5), Point(2.4, 2.5));
	std::cout << std::endl;
	return (0);
}
