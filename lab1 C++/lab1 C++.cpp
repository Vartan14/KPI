//ІП-13 Карамян В.С.
//Варіант 15
//Створити текстовий файл. Переписати його компоненти до нового текстового файлу,
//вставляючи в кінець кожного рядка літеру, що є останнью в першому слові рядка.
//Вивести вміст вихідного і створеного файлів.

#include"module.h"

int main()
{
    string initName = nameTheFile();
    createFile(initName);   
    
    string editName = nameTheFile();
    editFile(initName, editName);

    outputFile(initName);
    outputFile(editName);
}



