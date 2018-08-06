#include <iostream>
using namespace std;

void _toLower(char * str)
{
    int i;
    for(i=0; str[i]!='\0'; i++)
    {
        str[i] |= 32;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        cout << "Expects 1 argument";
    else
    {
        _toLower(argv[1]);
        cout << argv[1];
    }
    cout << endl;
    return 0;
}