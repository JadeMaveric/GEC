// Julius Alphonso
// 171105004

/* Write a program to compare 2 dates entered by the user.
 * Make a structure named 'Date' to store the elements [day, month, year]
 * If the dates are equal -> print "Dates are equal"
 * Otherwise -> print "Dates are not equal"
 */
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Date {
    short int day;
    short int month;
    short int year;
};

inline bool operator==(Date A, Date B) {
    return (A.day==B.day) && (A.month==B.month) && (A.year==B.year);
}

int main() {
    Date user1, user2;
    
    cout << "Enter 2 dates [dd mm yyyy]\n";

    cout << "Date 1: ";
    cin  >> user1.day >> user1.month >> user1.year;

    cout << "Date 2: ";
    cin  >> user2.day >> user2.month >> user2.year;

    if (user1==user2)
        cout << "Both dates are equal!" << endl;
    else
        cout << "The dates aren't equal." << endl;

    return 0;
}