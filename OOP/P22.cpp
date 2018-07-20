#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Student
{
    char name[20];
    int roll;
    int age;
};

void display( Student student )
{
    cout << "Details..." << endl
         << "Name : " << student.name << endl
         << "Roll : " << student.roll << endl
         << "Age  : " << student.age << endl;
}

int main()
{
    Student student[5];

    for(int i = 0; i < 5; i++)
    {
        cout << "Enter student details" << endl;
        cout << "Name: ";
        cin  >> student[i].name;
        cout << "Roll: ";
        cout << i + 1 << endl;
        student[i].roll = i + 1;
        cout << "Age : ";
        cin  >> student[i].age;
        cout << endl;
    }

    display(student[1]);
}