#include"module.h"

int MaterialPoint::Count;

MaterialPoint::MaterialPoint()
{}

MaterialPoint::MaterialPoint(float x, float y, float z, float v1, float v2, float v3)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->motionVector[0] = v1;
	this->motionVector[1] = v2;
	this->motionVector[2] = v3;
	number = ++Count;
}

void MaterialPoint::print()
{
	cout << "Point " << number << "\nx = " << x << "\ny = " << y << "\nz = " << z;
	cout << "\nv = (" << motionVector[0] << ", " << motionVector[1] << ", " << motionVector[2] << ")\n\n";
}

bool  MaterialPoint::inFirstOctant(int t)
{


	int x1 = x + motionVector[0] * t;
	int y1 = y + motionVector[1] * t;
	int z1 = z + motionVector[2] * t;

	if (x1 > 0 && y1 > 0 && z1 > 0)
		return true;
	else
		return false;
}

MaterialPoint* createArr(int size)
{
	MaterialPoint* points = new MaterialPoint[size];
	float x, y, z, v1, v2, v3;
	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter initial coordinates\n";
		cout << "x:"; cin >> x;
		cout << "y:"; cin >> y;
		cout << "z:"; cin >> z;
		cout << "Enter vector of uniform motion\n";
		cout << "v1:"; cin >> v1;
		cout << "v2:"; cin >> v2;
		cout << "v3:"; cin >> v3;
		cout << endl;
		MaterialPoint point(x, y, z, v1, v2, v3);
		points[i] = point;
	}
	return points;
}

int enterSize()
{
	int size;
	do
	{
		cout << "Enter number of points: "; cin >> size;
	} while (size <= 0);

	return size;
}

void outputArr(MaterialPoint* points, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		points[i].print();
	}
}

void pointsInFirstOctant(MaterialPoint* points, int size)
{
	int t;

	do
	{
		cout << "Enter time in seconds: "; cin >> t;
	} while (t <= 0);

	cout << "Numbers points in first octant:\n";
	for (size_t i = 0; i < size; i++)
	{
		if (points[i].inFirstOctant(t))
		{
			cout <<"point " << points[i].getNumber() << '\n';
		}
	}
	cout << endl;


}
