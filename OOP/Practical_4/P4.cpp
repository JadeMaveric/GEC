#include <iostream>
using namespace std;

int _substr(char * str, char * sub)
{
    int i, j;
    for (i=0; str[i]!='\0'; i++)
        if(str[i] == sub[0])
        {
            for(j=1; sub[j]!='\0'; j++)
            {
                if(sub[j] != str[i+j])
                    break;
            }
            if( sub[j] == '\0')
                return i;
        }
    return -1;
}

int main(int argc, char **argv)
{
    int j;
    if (argc != 3)
        cout << "Expects 2 inputs";
    else
    {
        for (j=_substr(argv[1], argv[2]); argv[1][j]!='\0'; j++)
            cout << argv[1][j];
    }
    cout << endl;
    return 0;
}