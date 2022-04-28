#pragma once
#include <iostream>
using namespace std;
class MaterialPoint
{
	float x;
	float y;
	float z;
	float motionVector[3];
	static int Count;
	int number;
public:
	MaterialPoint();	
	MaterialPoint(float x, float y, float z, float v1, float v2, float v3);
	void print();
	bool inFirstOctant(int t);
	int getNumber()
	{
		return number;
	}
		
};


MaterialPoint* createArr(int);
int enterSize();
void outputArr(MaterialPoint* , int );
void pointsInFirstOctant(MaterialPoint* , int );