#include "funcs.h"

template<class T>
void changeFunctoin(vector<T> &list, char mode, int num)
{
    for (size_t i = 0; i < list.size(); i++)
    {
        if (mode == '+')
            list[i].increaseBy(num);
        else if (mode == '-')
            list[i].decreaseBy(num);
    }

}

template<class T>
void printList(vector<T> list)
{
    for (size_t i = 0; i < list.size(); i++)
    {
        list[i].print();
    }
}

template<class T>
T maxFunction(vector<T> list, double x)
{
    double maxValue = list[0].calculate(x);
    T maxFunc = list[0];
    for (size_t i = 1; i < list.size(); i++)
    {
        if (list[i].calculate(x) > maxValue)
        {
            maxFunc = list[i];
            maxValue = list[i].calculate(x);
        }
    }
    return maxFunc;
}