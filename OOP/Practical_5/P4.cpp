#include <iostream>
using namespace std;

class Student {
private:
    int roll_no;
    char name[20];
    char class_[8];
    int marks[5];
    float percentage;

    float calculate() {
        return (marks[0] + marks[1] + marks[2] + marks[3] + marks[4])/5;
    }

public:
    Student( int _roll, char * _name, char * _class ) {
        roll_no = _roll;
        for (int i=0; _name[i]!='\0'; i++)
            name[i] = _name[i];
        for (int i=0; _class[i]!= '\0'; i++)
            class_[i] = _class[i];
    }

    void read_marks() {
        cout << "Enter Marks: ";
        for (int i=0; i<5; i++) {
            cout << i+1 << ": ";
            cin  >> marks[i];
        }
        percentage = calculate();
    }

    void display_marks() {
        cout << "Marks...\n";
        for (int i=0; i<5; i++) {
            cout << i+1 << ": ";
            cout <<  marks[i] << "\n";
        }
        cout << endl;
    }
};