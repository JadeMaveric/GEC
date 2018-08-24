#include <iostream>
using namespace std;

class Worker {
private:
    char w_name[25], w_no[25];
    float hours_worked;
    float wage_rate;
    float total_wage;

    float calc_wage() {
        return hours_worked * wage_rate;
    }

public:
    void in_data() {
        cout << "Enter details...\n"
             << "Name: ";
        cin.getline(w_name, 24);
        cout << "Num : ";
        cin  >> w_no;
        cout << "Hours Worked: ";
        cin  >> hours_worked;
        cout << "Wage Rate   : ";
        cin  >> wage_rate;
        
        total_wage = calc_wage();
    }

    void out_data() {
        cout << "Details...\n"
             << "Name: " << w_name << "\n"
             << "Num : " << w_no << "\n"
             << "Hours Worked: " << hours_worked << "\n"
             << "Wage Rate   : " << wage_rate << "\n"
             << "Total Wage  : " << total_wage << "\n"
             << endl;
    }
};