#include "Point.hpp"

Point::Point(): x(0), y(0)
{
}

Point::Point(const float x, const float y): x(x), y(y)
{
}

Point::Point(const Point &point): x(point.x), y(point.y)
{
}

const Fixed	&Point::getX() const
{
	return this->x;
}

const Fixed	&Point::getY() const
{
	return this->y;
}

Point	&Point::operator=(const Point &point)
{
	(void) point;
	return *this;
}

bool	Point::operator==(const Point &point) const
{
	return this->x.toInt() == point.x.toInt() && this->y.toInt() == point.y.toInt();
}

Point::~Point()
{
}

std::ostream	&operator<<(std::ostream &stream, const Point &point)
{
	stream << "(" << point.getX() << ", " <<  point.getY() << ")";
	return stream;
}
