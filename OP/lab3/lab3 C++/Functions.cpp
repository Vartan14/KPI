#include "Functions.h"

double inputX()
{
	string x;
	double xFloat;
	while (true)
	{
		cout << "x: "; cin >> x;
		try
		{
			xFloat = stof(x);
			break;
		}
		catch (const std::exception&)
		{
			cout << "Enter float number!\n";
		}

	}
	return xFloat;
}

double inputY()
{
	string y;
	double yFloat;
	while (true)
	{
		cout << "y: "; cin >> y;
		try
		{
			yFloat = stof(y);
			break;
		}
		catch (const std::exception&)
		{
			cout << "Enter float number!\n";
		}

	}
	return yFloat;
}

double inputR()
{
	string r;
	double rFloat;
	while (true)
	{
		cout << "radius: "; cin >> r;
		try
		{
			rFloat = stof(r);
			break;
		}
		catch (const std::exception&)
		{
			cout << "Enter float number!\n";
		}

	}
	return rFloat;
}

vector<Circle> createCircle()
{
	vector<Circle> circles;
	Circle pushCircle;
	int size = 3;
	string mode;
	double x, y, r;

	cout << "Enter 3 circles:\n";

	for (size_t i = 0; i < size; i++)
	{
		while (true)
		{
			cout << "Choose enter mode:\n1 - x, y, radius\n2 - x, y\n3 - radius\n4 - standard circle\n>>>";
			cin >> mode;

			if (mode == "1")
			{
				x = inputX();
				y = inputY();
				r = inputR();
				Circle circle(x, y, r);
				pushCircle = circle;
				break;
			}
			else if (mode == "2")
			{
				x = inputX();
				y = inputY();
				Circle circle(x, y);
				pushCircle = circle;
				break;
			}
			else if (mode == "3")
			{
				r = inputR();
				Circle circle(r);
				pushCircle = circle;
				break;
			}
			else if (mode == "4")
			{
				Circle circle;
				pushCircle = circle;
				break;
			}
		}
		circles.push_back(pushCircle);
		cout << endl;
	}
	return circles;
}

void printCircles(vector<Circle> list)
{
	for (size_t i = 0; i < list.size(); i++)
	{
		list[i].print();
	}
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