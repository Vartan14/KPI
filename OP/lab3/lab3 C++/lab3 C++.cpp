#include "Circle.h"
#include "Functions.h"

int main()
{	
	vector<Circle> circles = createCircle();
	cout << "=================================================\n";

	printCircles(circles);
	cout << "=================================================\n";

	++circles[0];
	circles[1]++;
	circles[2] = circles[2] * 3;
	printCircles(circles);
	cout << "=================================================\n";

	Circle maxCircle = maxCircleLength(circles);
	cout << "Circle with a max length:\n";
	maxCircle.print();
}