#include "Circle.h"

int main()
{
	Circle C1(12, -29, 3), C2(12, 45), C3(7);
	cout << "=======================================\n";
	C1.print();
	C2.print();
	C3.print();
	cout << "=======================================\n";

	++C1;
	C2++;
	C3 = C3 * 3;
	
	C1.print();
	C2.print();
	C3.print();
	cout << "=======================================\n";
	
	vector<Circle> circles{C1, C2, C3};	
	Circle maxCircle = maxCircleLength(circles);
	cout << "Circle with a max length:\n";
	maxCircle.print();
}