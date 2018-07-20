#include <iostream>

using namespace std;

struct Imperial
{
    int in, ft;
};

Imperial add( Imperial d1, Imperial d2 )
{
    Imperial result;

    result.in = (d1.in + d2.in)%12;
    result.ft = (d1.in + d2.in)/12 + d1.ft + d2.ft;

    return result;
}

int main()
{
    Imperial A, B, C;

    cout << "dist 1: ";
    cin  >> A.ft >> A.in;
    cout << "dist 2: ";
    cin  >> B.ft >> B.in;

    C = add( A, B );

    cout << "A + B = " << C.ft << "'" << C.in <<"\"" << endl;

    return 0;
}