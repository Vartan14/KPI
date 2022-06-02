#include "LinearFunction.h"

void LinearFunction::print()
{
    if (a == 0)
        cout << "y = " << b;
    else if (a == 1)
        cout << "y = x";
    else if (a == -1)
        cout << "y = -x";
    else
        cout << "y = " << a << "x";

    if (b > 0)
        cout << " + " << b;
    else if (b < 0)
        cout << " - " << abs(b);
    cout << endl;
}

double LinearFunction::calculate(double x)
{
    return a * x + b;
}