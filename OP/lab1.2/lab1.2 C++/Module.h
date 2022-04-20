#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
    Date();
    void setDate();
    
};

struct Employee
{
    char fullName[40] = "";
    Date birthday;
    Date recrDate;
};

string initFileName();
void createList(string);
vector<Employee> readFile(string);
Employee addEmployee();
void outputEmps(Employee);
void outputList(vector<Employee>);
Date inputDate();
void outputOver40yo(vector<Employee>, Date);
void outputOver20exp(vector<Employee>, Date);
void deleteLess1exp(vector<Employee>, Date, string);
bool calculateYears(Employee, Date, string, int );
