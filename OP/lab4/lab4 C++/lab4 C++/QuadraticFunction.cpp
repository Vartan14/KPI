#include "QuadraticFunction.h"
void QuadraticFunction::print()
{
    if (a == 0)
        cout << "y = ";
    else if (a == 1)
        cout << "y = x^2";
    else if (a == -1)
        cout << "y = -x^2";
    else
        cout << "y = " << a << "x^2";


    if (b == 1)
        cout << " + x";
    else if (b == -1)
        cout << " - x";
    else if (b != 0 )
    {
        if (a != 0)
        {
            if (b > 0)
                cout << " + " << b << "x";
            else
                cout << " - " << abs(b) << "x";
        }
        else
        {
            cout << " " << b << "x";
        }        
    }

    if (a == 0 && b == 0)
        cout << c;
    else if (c > 0)
        cout << " + " << c;
    else if (c < 0)
        cout << " - " << abs(c);
    

    cout << endl;
}
double QuadraticFunction::calculate(double x)
{
    return a * pow(x, 2) + b * x + c;
}