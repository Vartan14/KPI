#pragma once
#include <fstream>
#include <vector>
#include "Tree.h"

string getFileName();

void printFile(string);

void readFile(string, Tree&);

void findIdentifier(Tree& , string , int , string );
