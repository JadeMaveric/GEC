#include <iostream>
#include <string.h>

using namespace std;

int _strlen(char * str)
{
    int i;
    for (i=0; str[i]!='\0'; i++);
    return i;
}

int numOfWords(char * str)
{
    int i, words = 0;
    for (i=1; i<=_strlen(str); i++)
    {
        switch (str[i])
        {
            case ' ': case '.': case '!': case '?': case ',': case ';': case ':':
                if (isalnum(str[i-1]))
                    words++;
                break;
        }
    }
    return words;
}

int main()
{
    char line[80];
    cin.getline(line, 80);
    cout << numOfWords(line) << " words";
    cout << endl;
    return 0;
}