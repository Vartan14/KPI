#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Circle.h"
using namespace std;

double inputX();
double inputY();
double inputR();
vector<Circle> createCircle();
void printCircles(vector<Circle>);
Circle maxCircleLength(vector <Circle> circles);
