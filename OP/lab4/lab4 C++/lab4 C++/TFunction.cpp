#include "TFunction.h"

TFunction::TFunction(double a, double b, double c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

void TFunction::increaseBy(double num)
{
    a += num;
    b += num;
    c += num;
}

void TFunction::decreaseBy(double num)
{
    a -= num;
    b -= num;
    c -= num;
}
