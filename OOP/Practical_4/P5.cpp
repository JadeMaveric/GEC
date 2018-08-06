#include <iostream>
#include <stdlib.h>
using namespace std;

int _strlen(char * str)
{
    int i;
    for (i=0; str[i]!='\0'; i++);
    return i;
}

char * _concat(char *dest, char *src)
{
    int i = _strlen(dest), j = _strlen(src), k;
    char * temp = new char[i+j-1];
    
    for(k=0; k<i; k++)
        temp[k] = dest[k];
    for(k=i; k<=i+j; k++)
        temp[k] = src[k-i];
    dest = temp;
    return temp;
}

int main(int argc, char ** argv)
{
    char *result;
    if (argc != 3)
        cout << "Expects 2 arguments";
    else
    {
        result = _concat(argv[1], argv[2]);
        cout << result;
    }
    cout << endl;
    delete result;
    return 0;
}