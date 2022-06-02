#include "funcs.h"

vector<LinearFunction> createLinearList()
{
    vector<LinearFunction> list;
    int size;
    double a, b;
    cout << "Enter number of linear functions n:";
    cin >> size;

    for (size_t i = 0; i < size; i++)
    {
        a = rand() % 101;
        b = rand() % 101;
        LinearFunction y(a, b);
        y.print();
        list.push_back(y);
    }
    return list;
}

vector<QuadraticFunction> createQuadraticList()
{
    vector<QuadraticFunction> list;
    int size;
    double a, b, c;
    cout << "\nEnter number of quadratic functions m:";
    cin.ignore();
    cin >> size;

    for (size_t i = 0; i < size; i++)
    {
        a = rand() % 201 - 100;
        b = rand() % 201 - 100;
        c = rand() % 201 - 100;
        QuadraticFunction y(a, b, c);
        y.print();
        list.push_back(y);
    }
    return list;
}