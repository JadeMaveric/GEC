// Julius Alphonso
// 171105004

/* Store their info of the students and implement the following functions
 * Write a structure to store roll number, age (18-25) and address of students (>10)
 *     a. To print the names of all students having age between 20 and 22.
 *     b. To print the names of all students having an even roll number
 *     c. To display the details of students whose roll number is inputted by the user
 */

#include <iostream>
#define NUM_OF_STUDENTS 2

using namespace std;

struct Student {
    char name[21];
    int roll;
    short int age;
    char address[31];
};

void displayAgeGroup(Student * student) {
    cout << "Students beween 19 and 23 years\n";
    for (int i=0; i<NUM_OF_STUDENTS; i++) {
        if ((student[i].age > 19) && (student[i].age < 23))
            cout << student[i].name << "\n" << endl;
    }
}

void displayEvenRoll(Student * student) {
    cout << "Students with even roll numbers\n";
    for (int i=0; i<NUM_OF_STUDENTS; i++) {
        if ((student[i].roll&1) == 0)
            cout << student[i].name << "\n" << endl;
    }
}

void displayDetails(Student * student) {
    int roll, i;
    cout << "Search by Roll Number\nEnter roll number";
    cin >> roll;

    for (i=0; i<NUM_OF_STUDENTS; i++) {
        if (student[i].roll == roll){
            cout << "Name: " << student[i].name << "\n"
                 << "Age : " << student[i].age << "\n"
                 << "Roll: " << student[i].roll << "\n"
                 << "Address: " << student[i].address << "\n"
                 << endl;
            break;
        }
    }

    if (i==NUM_OF_STUDENTS)
        cout << "Student not found\n";
}

int main() {
    Student comp[NUM_OF_STUDENTS];

    cout << "Enter student details:\n";
    
    for(auto&& student : comp) {
        cout << "Name: ";
        cin.getline(student.name, 20);
        cout << "Roll: ";
        cin >> student.roll;
        cin.ignore();
        student.age = 0;
        while(student.age<18 || student.age>25) {
            cout << "Age : ";
            cin >> student.age;
            cin.ignore();
        }
        cout << "Address: ";
        cin.getline(student.address, 30);
        cout << endl;
    }
    
    displayAgeGroup(comp);
    displayEvenRoll(comp);
    displayDetails(comp);
}
