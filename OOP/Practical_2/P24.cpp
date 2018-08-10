#include <iostream>

using namespace std;

struct Complex
{
    double real, img;
};

Complex add( Complex A, Complex B )
{
    Complex result;

    result.real = A.real + B.real;
    result.img  = A.img  + B.img;

    return result;
}

Complex sub( Complex A, Complex B )
{
    Complex result;

    result.real = A.real - B.real;
    result.img  = A.img  - B.img;

    return result;
}

Complex prod( Complex A, Complex B )
{
    Complex result;

    result.real = A.real*B.real - A.img*B.img;
    result.img  = A.img*B.real + A.real*B.img;

    return result;
}

Complex div( Complex A, Complex B )
{
    Complex result;

    result.real = A.real*B.real + A.img*B.img;
    result.real /= B.real*B.real + B.img*B.img;

    result.img = A.img*B.real - A.real*B.img;
    result.img /= B.real*B.real + B.img*B.img;

    return result;
}

int main()
{
    Complex c1, c2, c3;

    cout << "Complex 1: ";
    cin  >> c1.real >> c2.img;

    cout << "Complex 2: ";
    cin  >> c2.real >> c2.img;
    
    //Add
    c3 = add( c1, c2 );
    cout << "Sum : " << c3.real << " + " << c3.img << "i\n";
    
    //Sub
    c3 = sub( c1, c2 );
    cout << "Diff: " << c3.real << " + " << c3.img << "i\n";

    //Mult
    c3 = prod( c1, c2 );
    cout << "Prod: " << c3.real << " + " << c3.img << "i\n";

    //Div
    c3 = div( c1, c2 );
    cout << "Div : " << c3.real << " + " << c3.img << "i\n";
}