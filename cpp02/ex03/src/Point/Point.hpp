#pragma once

#include "Fixed/Fixed.hpp"
#include <fstream>

class Point {
	private:
		const Fixed	x;
		const Fixed	y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &point);

		const Fixed	&getX() const;
		const Fixed	&getY() const;

		Point	&operator=(const Point &point);

		~Point();
};

std::ostream	&operator<<(std::ostream &stream, const Point &point);
