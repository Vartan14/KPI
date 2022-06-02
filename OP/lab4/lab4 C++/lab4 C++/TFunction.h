#pragma once
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

class TFunction
{
protected:
    double a, b, c;
public:

    TFunction(double, double, double = 0);

    void increaseBy(double);

    void decreaseBy(double);

    virtual void print() = 0;

    virtual double calculate(double) = 0;

};