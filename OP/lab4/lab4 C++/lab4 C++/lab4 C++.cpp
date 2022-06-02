//Карамян В. ІП-13
//Варіант 15
//Спроектувати клас TFunction, який представляє функцію і містить методи збільшення/зменшення всіх коефіцієнтів функції
//на вказану величину та обчислити значення функції в заданій точці. На основі цього класу створити класи-нащадки
//Лінійна функція (виду a1x+a0) та Квадратична функція (виду b2x^2+b1x+b0). Створити n лінійних функцій та m квадратичних
//функцій, згенерувавши дані для них випадковим чином. Коефіцієнти лінійних ф-цій збільшити на 3, а квадратичних - 
//зменшити на 2. Визначити функцію, яка має найбільше значення у введеній користувачем точці.

#include "funcs.h"

int main()
{
    srand(time(NULL));
    vector<LinearFunction> list1 = createLinearList();
    vector<QuadraticFunction> list2 = createQuadraticList();

    changeFunctoin(list1, '+', 3);
    cout << "\nLinear functions increased by 3:\n";
    printList(list1);

    changeFunctoin(list2, '-', 2);
    cout << "\nQuadratic functions decreased by 2:\n";
    printList(list2);

    double x;
    cout << "\nEnter value of x0:"; cin >> x;

    LinearFunction maxLin = maxFunction(list1, x);
    QuadraticFunction maxQuad = maxFunction(list2, x);

    cout << "\nFunction with a max value in a dot " << x << ":\n";
    if (maxLin.calculate(x) > maxQuad.calculate(x))
    {
        maxLin.print();
        cout << "Value = " << maxLin.calculate(x) << endl;
    }
    else
    {
        maxQuad.print();
        cout << "Value = " << maxQuad.calculate(x) << endl;
    }

}

