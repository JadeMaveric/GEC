/* Program to find the length of the string
 * Julius Alphonso
 * 171105004
 * 3/8/2018
 * */

#include <iostream>
#include <string.h>

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
    char word[30];
    if (argc == 1)
        cout << "Expects one arguement";
    else
    {
        strcpy(word, argv[1]);
        _revstr(argv[1]);
        if(strcmp(word, argv[1]))
            cout << "Not a palindrome";
        else
            cout << "Palindrome";
    }
    cout << endl;
    return 0;
}