#pragma once
#include "LinearFunction.h"
#include "QuadraticFunction.h"

vector<LinearFunction> createLinearList();

vector<QuadraticFunction> createQuadraticList();

template<class T>
void changeFunctoin(vector<T>& list, char mode, int num);

template<class T>
void printList(vector<T> list);

template<class T>
T maxFunction(vector<T> list, double x);

#include "templateFuncs.cpp"