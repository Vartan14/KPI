#include "Circle.h"

Circle:: Circle(double x, double y, double r)
{
	this->x = x;
	this->y = y;
	this->radius = r;
}

Circle::Circle(double x, double y)
{
	this->x = x;
	this->y = y;
	this->radius = 1;
}

Circle::Circle(double r)
{
	this->x = 0;
	this->y = 0;
	this->radius = r;
}

double Circle::getX()
{
	return x;
}
double Circle::getY()
{
	return y;
}
double Circle::getRadius()
{
	return radius;
}

double  Circle::circleLength()
{
	return 2 * radius * M_PI;
}

void Circle::print()
{
	cout << ">> Circle <<\n";
	cout << "Coordinates of center:\tx = " << x << "\ty = " << y;
	cout << "\nRadius = " << radius;
	cout << "\nCircle length: " << setprecision(4) << circleLength() << "\n\n";
}

Circle Circle::operator++()
{
	++this->x;
	return *this;
}

Circle Circle::operator++(int unused)
{
	++this->y;
	return *this;
}

Circle Circle::operator*(int num)
{
	this->radius *= num;
	return *this;
}


