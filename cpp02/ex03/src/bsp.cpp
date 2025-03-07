#include "Point/Point.hpp"

static float	cross_product(const Point &a, const Point &b, const Point &p)
{
	return (b.getX().toFloat() - a.getX().toFloat()) * (p.getY().toFloat() - a.getY().toFloat())
			- (b.getY().toFloat() - a.getY().toFloat()) * (p.getX().toFloat() - a.getX().toFloat());
}

bool	bsp(Point const a, Point const b, Point const c, Point const p)
{
	float	cross_abp = cross_product(a, b, p);
	float	cross_bcp = cross_product(b, c, p);
	float	cross_cap = cross_product(c, a, p);

	return (cross_abp > 0 && cross_bcp > 0 && cross_cap > 0)
			|| (cross_abp < 0 && cross_bcp < 0 && cross_cap < 0);
}
