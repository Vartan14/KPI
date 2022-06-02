#pragma once
#include "TFunction.h"

class QuadraticFunction : public TFunction
{
public:
    QuadraticFunction(double a, double b, double c) :
        TFunction(a, b, c)
    {}
    void print();
    double calculate(double);
};