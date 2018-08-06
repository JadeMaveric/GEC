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

void _revstr(char * str)
{
    int i;
    int len = _strlen(str)-1;
    for (i=0; i<len; i++)
    {
        char temp = str[i];
        str[i] = str[len-i];
        str[len-i] = temp;
    }
}

int main(int argc, char **argv)
{
    if (argc == 1)
        cout << "Expects one arguement";
    else
    {
        _revstr(argv[1]);
        cout << argv[1];
    }
    cout << endl;
    return 0;
}