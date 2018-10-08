#include <iostream>
#include <iomanip>

#define MAX 0

using namespace std;

int main() {
    struct {char name[20], code[10]; int cost;} list[MAX];
    for (int i=0; i<MAX; i++) {
        cout << "Item" << i+1 << "\n"
             << "Name: ";
        cin  >> list[i].name;
        cout << "Code: ";
        cin  >> list[i].code;
        cout << "Cost: ";
        cin  >> list[i].cost;
    }
    
    cout << cout.width(10) << "NAME"
         << cout.width(10) << "CODE"
         << cout.width(6)  << "COST"
         << "\n__________________\n";

    for (int i=0; i<MAX; i++) {
        cout << left  << list[i].name << "\t"
             << left  << list[i].code << "\t"
             << right << cout.precision(2) << fixed << list[i].cost
             << endl;
    }
}