
#include <iostream>
#include <iomanip>

using namespace std;

ostream& my_manip( ostream& dout ) {
    dout.unsetf(ios::adjustfield|ios::floatfield);
    dout.width(10);
    dout.setf(ios::right, ios::adjustfield);
    dout.precision(1);
    dout.fill('*');
    dout.setf(ios::fixed, ios::floatfield);
    return dout;
}

int main() {
    double x = 0;
    cout << my_manip << x << endl;
}