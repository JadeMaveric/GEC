#include <stdio.h>

void revstr(char * str)
{
    if (str[0] == '\0')
        return;
    else
        revstr(&str[1]);
        printf("%c", str[0]);
}

int main()
{
    char str[] = "This bit of code is for a DSA assingment";
    revstr(str);
    return 0;
}