#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>

using namespace std;

class Circle
{
	double x;
	double y;
	double radius;
public:
	Circle(double, double, double);
	
	Circle(double, double);
	
	Circle(double = 1);

	Circle(const Circle&);
		
	double getX();
	
	double getY();
	
	double getRadius();
	
	double circleLength();
	
	void print();
	
	Circle operator++();
	
	Circle operator++(int);
	
	Circle operator*(int);	
};

Circle maxCircleLength(vector <Circle>);