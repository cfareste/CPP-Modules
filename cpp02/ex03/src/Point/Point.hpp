#pragma once

#include "Fixed/Fixed.hpp"

class Point {
	private:
		const Fixed	x;
		const Fixed	y;

	public:
		Point();
		Point(const float x, const float y);
		Point(Point &point);

		const Fixed	&getX();
		const Fixed	&getY();

		Point	&operator=(const Point &point);

		~Point();
};
