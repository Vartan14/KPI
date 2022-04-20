//ІП-13 Карамян В.С
//Варіант 15
//Створити файл із списком працівників підприємства: ПІБ, дата народження, дата прийому на роботу.
//Вивести список співрботників, старших за 40 років, та співробітників,які працюють на підприємстві
//не менше 20 років. Видалити з файлу інформацію про співробітників,які працюють менше року.

#include "Module.h"

int main()
{    
    string fileName = "init.bin";// = initFileName();
    createList(fileName);

    vector<Employee> emps = readFile(fileName);
    outputList(emps);

    Date todayDate = inputDate();
    outputOver40yo(emps, todayDate);
      
    outputOver20exp(emps, todayDate);

    deleteLess1exp(emps, todayDate, fileName);

    vector<Employee> newEmps = readFile(fileName);
    outputList(newEmps);
}


