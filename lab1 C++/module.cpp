#include "module.h"

void createFile(string fileName)
{
    ofstream fout;   
    char mode;   
    cout << "Please, select the write mode.To create a new file, press 1.To append to an already existing file, press 2.\n";
    while (true)
    {
        cin >> mode;
        if (mode == '1')
        {
            fout.open(fileName);
            break;
        }
        else if (mode == '2')
        {
            fout.open(fileName, ios::app);
            break;
        }
        else
        {
            cout << "Error. Please press 1 or 2.\n";
        }
    }

    if (!fout.is_open())
    {
        cout << "Error. File is not found.\n";
    }
    else
    {
        cout << "Enter the text. To finish press Ctrl+X:\n";
        cin.ignore();
        while (1) {
            string line;
            getline(cin, line);
            if (line[0] == 24)
                break;
            fout << line << endl;
            
        }


    }
    fout.close();
}

string nameTheFile()
{
    string fileName;
    cout << "Please, enter file name:\n";
    cin >> fileName;
    return fileName;
}

void outputFile(string fileName)
{
    ifstream fin(fileName);

    if (!fin.is_open())
    {
        cout << "Error. File is not found.\n";
    }
    else
    {
        cout <<endl<< fileName <<":" << endl;
        string str;
        while (!fin.eof())
        {
            str = "";
            getline(fin, str);
            cout << str << endl;
        }
        fin.close();
    }


}

void editFile(string initName, string editName)
{

    ifstream fin(initName);
    ofstream fout(editName);

    if (!(fin.is_open() || fout.is_open()))
    {
        cout << "Error. File is not found.\n";
    }
    else
    {
        int pos;
        string line;
              
        while (!fin.eof())        
        {
            line = "";
            getline(fin, line);

            if (line == "") //empty str
            {
                fout << endl;              
                continue;
            }

            int i = 0;                    
            while (line[i] == ' ') //find the first word
            {
                i++;               
            }
            pos = line.find(' ', i);   

            if (pos == -1) //1 word
                pos = line.length();            
                
            line += line[pos - 1];
            fout << line << endl;           
        }
        
        fout.close();
        fin.close();
    }
}