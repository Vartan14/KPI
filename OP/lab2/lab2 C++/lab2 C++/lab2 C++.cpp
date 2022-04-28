//Карамян Вартан ІП-13
//Варіант 15
//Розробити клас "матеріальна точка", яка характеризується координатами початкового положення
//та вектором рівномірної швидкості v = (v1, v2, v3).Створити масив об'єктів даного класу.
//Визначити точки(їх номера), які за введений користувачем час t попадають у перший октант.

#include"module.h"

int main()
{
	int size = enterSize();
	MaterialPoint *points = createArr(size);
	outputArr(points, size);
	pointsInFirstOctant(points, size);
	delete[] points;	
}