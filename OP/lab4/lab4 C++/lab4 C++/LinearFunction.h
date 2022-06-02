#pragma once
#include "TFunction.h"

class LinearFunction : public TFunction
{
public:
    LinearFunction(double a, double b) :
        TFunction(a, b)
    {
    }
    void print();
    double calculate(double x);
};