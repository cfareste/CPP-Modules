#include "Point.hpp"

Point::Point(): x(0), y(0)
{
}

Point::Point(const float x, const float y): x(x), y(y)
{
}

Point::Point(Point &point): x(point.x), y(point.y)
{
}

const Fixed	&Point::getX()
{
	return this->x;
}

const Fixed	&Point::getY()
{
	return this->y;
}

Point	&Point::operator=(const Point &point)
{
	(void) point;
	return *this;
}

Point::~Point()
{
}
