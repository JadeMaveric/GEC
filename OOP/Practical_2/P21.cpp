#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Student
{
    char name[20];
    int roll;
    int age;
    int marks;
};

int main()
{
    Student student;

    cout << "Enter student details" << endl;
    cout << "Name: ";
    cin  >> student.name;
    cout << "Roll: ";
    cin  >> student.roll;
    cout << "Age : ";
    cin  >> student.age;
    cout << "Marks: ";
    cin  >> student.marks;

    cout << "Details..." << endl
         << "Name : " << student.name << endl
         << "Roll : " << student.roll << endl
         << "Age  : " << student.age << endl
         << "Marks: " << student.marks << endl;
}