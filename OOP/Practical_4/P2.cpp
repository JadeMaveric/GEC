/* Program to find the length of the string
 * Julius Alphonso
 * 171105004
 * 3/8/2018
 * */

#include <iostream>

using namespace std;

int _strlen(char * str)
{
    int i;
    for (i=0; str[i]!='\0'; i++);
    return i;
}

void _disprevstr(char * str)
{
    int i;
    for (i=_strlen(str)-1; i>=0; i--)
        cout << str[i];
}

int main(int argc, char **argv)
{
    if (argc == 1)
        cout << "Expects one arguement";
    else
        _disprevstr(argv[1]);
    cout << endl;
    return 0;
}