#include <iostream>

using namespace std;

struct Rational
{
    int nu,de;
};

Rational add( Rational A, Rational B )
{
    Rational result;

    result.nu = A.nu*B.de + A.de*B.nu;
    result.de = A.de * B.de;

    return result;
}

int main()
{
    Rational r1, r2, r3;

    cout << "Rational 1: ";
    cin  >> r1.nu;
    cin.ignore();
    cin  >> r1.de;

    cout << "Rational 2: ";
    cin  >> r2.nu;
    cin.ignore();
    cin  >> r2.de;

    r3 = add( r1, r2 );
    cout << "Sum: " << r3.nu << "/" << r3.de;

    cout << endl;

    return 0;
}