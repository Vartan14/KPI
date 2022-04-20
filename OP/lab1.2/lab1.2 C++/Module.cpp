#include "Module.h"

string initFileName()
{
    string name;
    cout << "Enter file name:";
    cin >> name;
    cout << "=============================================================\n";
    return name;
}

Date::Date()
{
    day = 0; month = 0; year = 0;
}

void Date::setDate()
{   
    do
    {
        cout << "day:";
        cin >> day ;
        cin.ignore();              
    } while (day<1 || day>31);
    
    do
    {
        cout << "month:";
        cin >> month;
        cin.ignore();
    } while (month<1 || month>12);

   

    do
    {
        cout << "year:";
        cin >> year;
        cin.ignore();
    } while (year < 1900 || year>2022);
    
    
    
}

void createList(string fileName)
{
    vector<Employee> employees;
    ofstream fout;
    char writeMode;
    cout << "Please, select the write mode.\nTo create a new file, press 1.\nTo append to an already existing file, press 2.\n>>>";
    while (true)
    {
        cin >> writeMode;
        cout << "=============================================================\n";
        if (writeMode == '1')
        {
            fout.open(fileName, ios::binary);
            break;
        }
        else if (writeMode == '2')
        {
            employees = readFile(fileName);
            outputList(employees);
            fout.open(fileName, ios::app | ios::binary);
            break;
        }
        else
        {
            cout << "Error. Please press 1 or 2.\n";
        }
    }

    Employee empl;
    char mode;

    if (!fout.is_open())
    {
        cout << "Error of opening file!";
    }
    else
    {
        while (true)
        {
            cout << "Do you want to add new employee?(Y/N)\n>>>";
            cin >> mode;
            cin.ignore();
            cout << "=============================================================\n";
            if (mode == 'Y')
            {
                empl = addEmployee();
                employees.push_back(empl);
                fout.write((char*)&empl, sizeof(Employee));
                cout << endl;
            }
            else if (mode == 'N')
            {
                break;
            }
        }

        fout.close();
    }
    
}

vector<Employee> readFile(string fileName)
{
    Employee emp;
    vector<Employee> emps;
    ifstream fin;

    fin.open(fileName, ios::binary);

    if (!fin.is_open())
    {
        cout << "Could not read a file\n";
    }
    else
    {
        while (fin.read((char*)&emp, sizeof(Employee)))
        {
            emps.push_back(emp);
        }
        fin.close();
    }
    
    return emps;
}

Employee addEmployee()
{

    Employee empl;
    cout << "Full name:";
    cin.get(empl.fullName, 40);

    cout << "Birthday\n";
    Date birthDate;
    birthDate.setDate();
    empl.birthday = birthDate;

    cout << "Date of recruitment\n";
    Date recruitmentDate;
    recruitmentDate.setDate();
    empl.recrDate = recruitmentDate;
    cout << "=============================================================";
    return empl;
}

void outputList(vector<Employee> emps)
{
    cout << "List of employees:" << endl;
    for (const auto &empl: emps)
    {
        outputEmps(empl);
    }   
    cout << "=============================================================\n";
}

void outputEmps(Employee empl)
{
    cout << empl.fullName;
    if (empl.birthday.day < 10)
        cout << "\t\t0" << empl.birthday.day << '.';
    else
        cout << "\t\t" << empl.birthday.day << '.';

    if (empl.birthday.month < 10)
        cout << '0' << empl.birthday.month;
    else
        cout << empl.birthday.month;
    cout << '.' << empl.birthday.year;

    if (empl.recrDate.day < 10)
        cout << "\t\t0" << empl.recrDate.day << '.';
    else
        cout << "\t\t" << empl.recrDate.day << '.';

    if (empl.recrDate.month < 10)
        cout << '0' << empl.recrDate.month;
    else
        cout << empl.recrDate.month;
    cout << '.' << empl.recrDate.year << endl;
}

Date inputDate()
{
    Date todayDate;
    cout << "Enter today's date\n";
    todayDate.setDate();
    return todayDate;
}

void outputOver40yo(vector<Employee> emps, Date todayDate)
{       
    cout << "=============================================================\n";
    cout << "Employees over 40 years old:\n";
    bool flag;
    for (const auto &empl: emps)
    {
        flag = calculateYears(empl, todayDate, "birthday", 40);
        if (flag)
        {
            outputEmps(empl);
        }
    }
}

void outputOver20exp(vector<Employee> emps, Date todayDate)
{  
    cout << "=============================================================\n";
    cout << "Employees over 20 years of experience:\n";
    bool flag;
    for (const auto& empl : emps)
    {
        flag = calculateYears(empl, todayDate,"recruitment", 20);
        if (flag)
        {
            outputEmps(empl);
        }
    }
}

void deleteLess1exp(vector<Employee> emps, Date todayDate, string fileName)
{
    ofstream fout(fileName, ios::binary);
    if (!fout.is_open())
    {
        cout << "Error of opening file!";
    }
    else
    {
        bool flag;        
        for (auto &empl : emps)
        {            
            flag = calculateYears(empl, todayDate, "recruitment", 1);
            if (flag)
            {
                fout.write((char*)&empl, sizeof(Employee));
            }
        }
        fout.close();
    }
    cout << "=============================================================\n";
    cout << "Employees with less than one year of experience were removed.\n";
}

bool calculateYears(Employee empl,Date todayDate, string dateMode, int years)
{
    Date date;

    if (dateMode == "birthday")
        date = empl.birthday;
    else if (dateMode == "recruitment")
        date = empl.recrDate;      

    bool flag = false;
    if (date.year < (todayDate.year - years))
    {
        flag = true;
    }
    else if (date.year == (todayDate.year - years))
    {
        if (date.month < todayDate.month)
        {
            flag = true;
        }
        else if (date.month == todayDate.month)
        {
            if (date.day < todayDate.day)
            {
                flag = true;
            }
        }
    }
    return flag;
}