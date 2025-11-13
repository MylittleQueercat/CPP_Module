#include "Point.hpp"

static	Fixed cross(Point const &a, Point const &b, Point const &p) {
	Fixed x1 = b.getX() - a.getX();
	Fixed y1 = b.getY() - a.getY();
	Fixed x2 = p.getX() - a.getX();
	Fixed y2 = p.getY() - a.getY();
	return (x1 * y2 - y1 * x2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed c1 = cross(a, b, point);
	Fixed c2 = cross(b, c, point);
	Fixed c3 = cross(c, a, point);

	// 如果任何一个为0，说明点在边或点上 → false
	if (c1 == 0 || c2 == 0 || c3 == 0)
		return (false);

	// 全正 or 全负
	bool pos = (c1 > 0 && c2 > 0 && c3 > 0);
	bool neg = (c1 < 0 && c2 < 0 && c3 < 0);

	return (pos || neg);
}