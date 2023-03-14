#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;

struct employee
{
    string name;
    int age;
    float salary;
};

// FUNCTIONS DECLERATION
void disEmpIndex(employee[],int);
void addNewEmp(employee[]);
void disAllEmp(employee[],int);

int main()
{
    int num;
    bool validInp = false;
    char choice;

    cout << "Enter number of employees " << endl;
    cin>>num;
    while (!validInp)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input is not a number!" << endl;
            cin>>num;
        }
        else
        {
            validInp =true;
        }
    }

// ENTER EMPLOYEE NUMBERS
    employee emp[num];
    for(int i=0; i<num; i++)
    {
        bool validInp = false;
        while (!validInp)
        {
            // ENTER NAME WITH VALIDATION
            std::cout << "Enter employee no."<<i+1<<" name: ";
            if (std::cin>>emp[i].name)
            {
                bool containsNumbers = false;
                for (char c : emp[i].name)
                {
                    if ( std::isdigit(c))
                    {
                        containsNumbers = true;
                        break;
                    }
                }
                if (!containsNumbers)
                {
                    validInp = true;
                }
                else
                {
                    std::cout << "Invalid input. Please enter a name with no numbers." << std::endl;
                }
            }
        }

        // ENTER AGE WITH VALIDATION
        do
        {
            cout << "Enter employee no."<<i+1<<" age: ";
            cin >> emp[i].age;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Input is not a number!" << endl;
                cin >> emp[i].age;
            }
            else
            {
                validInp =true;
            }
        }
        while (!validInp);

        // ENTER SALARY WITH VALIDATION
        do
        {
            cout << "Enter employee no."<<i+1<<" salary: ";
            cin >> emp[i].salary;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Input is not a number!" << endl;
                cin >> emp[i].salary;
            }
            else
            {
                validInp =true;
            }
        }
        while (!validInp);
        cout<<endl;
    }
    cout<<"\nEmployees' data entered successfully"<<endl;
    cout<<"-----------------------------------------------------"<<endl;

    do
    {
        cout<<"\nEnter your choice\n [d] to display specific employee\n [a] to add info of new employee\n [o] to display all employees\n [e] for exit"<<endl;
        cin>>choice;

        switch (choice)
        {
        case 'd':
        case 'D':
            int index;
            cout<<"Enter employee no. to display info "<<endl;
            cin>>index;
            disEmpIndex(emp,index-1);
            break;

        case 'a':
        case 'A':
            addNewEmp(emp);
            break;

        case 'o':
        case 'O':
            system("cls");
            disAllEmp (emp,num);
            break;

        default:
            cout<<"invalid input"<<endl;
        }
    }
    while (choice!='e');

    return 0;
}


//void employee::disEmpIndex ()
//{
//    cout << "Name: " << name << endl;
//    cout << "Age: " << age << endl;
//    cout << "Salary: " << salary << endl;
//
//}

// FUNCTIONS IMPLEMENTATION

void disEmpIndex (employee arr[],int n)
{
    cout << "Name: " << arr[n].name << endl;
    cout << "Age: " << arr[n].age << endl;
    cout << "Salary: " << arr[n].salary << endl;
}

void addNewEmp (employee arr[])
{

    int index;
    cout<< "\nEnter employee no. want to change info "<<endl;
    cin>>index;
    cout << "Enter employee no."<<index<<" name: ";
    cin >> arr[index-1].name;
    cout << "Enter employee no."<<index<<" age: ";
    cin >> arr[index-1].age;
    cout << "Enter employee no."<<index<<" salary: ";
    cin >> arr[index-1].salary;
}


COORD coord= {0,0}; // this is global variable
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void disAllEmp (employee arr[],int n)
{
    int headX=3, headY=2;
    int labelX=3, labelY=3;
    int dataX=3,  dataY=4;
    for (int i=0; i<n; i++)
    {
        gotoxy(headX,headY);
        cout<< "Employee no. "<<i+1<<" information"<<endl;
        headY+=6;

        gotoxy(labelX,labelY);
        cout<< "Name ";
        labelX+=10;
        gotoxy(dataX,dataY);
        cout<<arr[i].name;
        dataX+=10;

        gotoxy(labelX,labelY);
        cout<< "Age ";
        labelX+=10;
        gotoxy(dataX,dataY);
        cout<<arr[i].age;
        dataX+=10;

        gotoxy(labelX,labelY);
        cout<< "Salary ";
        gotoxy(dataX,dataY);
        cout<<arr[i].salary;

        labelX=3;
        labelY+=6;
        dataX=3;
        dataY+=6;
    }
}
