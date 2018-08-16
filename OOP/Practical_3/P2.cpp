// Julius Alphonso
// 171105004

/* Write a structure to store the info: name, acc no. & balance of 10 customers.
 * Store their info and implement the following functions
 *     a. To print names and other details (where balance > 200)
 *     b. To add Rs. 100 to balance of all accounts (where balance > 1000). 
 *        Print new balance
 */

#include <iostream>
#define NUM_OF_ACCOUNTS 2
using namespace std;

struct Account {
    char name[21];
    char ac_no[11];
    unsigned int balance;
};

void displayMin200Balance(Account *account) {
    for (int i=0; i<NUM_OF_ACCOUNTS; i++)  {
        if (account[i].balance > 200) {
            cout << "Name   : " << account[i].name << "\n"
                 << "A/C No : " << account[i].ac_no << "\n"
                 << "Balance: " << account[i].balance << "\n";
            cout << endl;
        }
    }
    cout << endl;
}

void updateAndDisplay(Account *account) {
    for (int i=0; i<NUM_OF_ACCOUNTS; i++) {
        if (account[i].balance >= 1000) {
            account[i].balance += 200;
            cout << "Updated Balance: " << account[i].balance << "\n";
        }
    }
    cout << endl;
}

int main() {
    Account clients[NUM_OF_ACCOUNTS];
    
    for(auto&& client : clients) {
        cout << "Name   : ";
        cin.getline(client.name, 20);
        cout << "A/C No : ";
        cin.getline(client.ac_no, 20);
        cout << "Balance: ";
        cin >> client.balance;
        cin.ignore();
        cout << endl;
    }

    displayMin200Balance(clients);
    updateAndDisplay(clients);
    
    return 0;
}