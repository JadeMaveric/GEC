#include <iostream>
using namespace std;

class Account {
private:
    char name[20];
    char ac_no[20];
    enum Type {S=(int)'S', C=(int)'C'} type;
    int  balance;

public:
    Account( char *_name, char *_ac_no, int _type, int _balance ) {
        for (int i=0; _name[i]!='\0'; i++)
            name[i] = _name[i];
        for (int i=0; _ac_no[i]!='\0'; i++)
            ac_no[i] = _ac_no[i];
        type = (Type)_type;
        balance = _balance;
    }

    int deposit( int money ) {
        balance += money;
        return balance;
    }

    int withdraw( int money ) {
        if (balance < 1000)
            return 0;
        else if (money > balance)
            return balance;
        else {
            balance = balance - money;
            return money;
        }
    }

    void display() {
        cout << "Details...\n"
             << "Name : " << name << "\n"
             << "AC no: " << ac_no << "\n"
             << "Type : " << (type==S?"Savings":"Current") << "\n"
             << "Balance:"<< balance << "\n"
             << endl;
    }
};