#include "head.h"
#include<cmath>

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}
void Point:: set(int x, int y)
{
	this->x = x;
	this->y = y;
}
int Point::getx() const
{
	return this->x;
}
int Point::gety() const
{
	return this->y;
}
double Point::distance(const Point& other)
{
	double ans = std::sqrt((this->x - other.x) * (this->x - other.x) +
		                   (this->y - other.y) * (this->y - other.y));
	return ans;
}