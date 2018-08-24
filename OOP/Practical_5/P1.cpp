#include <iostream>
using namespace std;

class Teacher {
private: 
    char name[20];
    char subject[10];
    float Basic, DA, HRA;
    float salary;

    float calculate() {
        salary = Basic + DA + HRA;
        return salary;
    }
public:
    void readData() {
        cout << "Enter details...\n"
             << "Name: ";
        cin.getline(name, 19);
        cout << "Sub : ";
        cin  >> subject;
        cout << "Basic: ";
        cin  >> Basic;
        cout  << "DA   : ";
        cin  >> DA;
        cout << "HRA  : ";
        cin  >> HRA;

        cout << "Salary: " << calculate() << "\n";
        cout << endl;
    }

    void displayData() {
        cout << "Details...\n"
             << "Name: " << name << "\n"
             << "Sub : " << subject << "\n"
             << "Base: " << Basic << "\n"
             << "DA  : " << DA << "\n"
             << "HRA : " << HRA << "\n"
             << "Sal : " << salary << "\n"
             << endl;
    }
};