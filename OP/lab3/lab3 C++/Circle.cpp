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

Circle::Circle(const Circle& obj)
{
	this->x = obj.x;
	this->y = obj.y;
	this->radius = obj.radius;
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
	double temp = 2 * radius * M_PI;
	return temp;
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

Circle maxCircleLength(vector <Circle> circles)
{
	Circle maxCircle = circles[0];
	double maxLength = circles[0].circleLength();
	for (size_t i = 1; i < circles.size(); i++)
	{
		if (circles[i].circleLength() > maxLength)
		{
			maxCircle = circles[i];
			maxLength = circles[i].circleLength();
		}
	}
	return maxCircle;
}