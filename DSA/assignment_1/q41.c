#include <stdio.h>

int punctuation(char ch)
{
    switch (ch)
    {
        case ' ': case '-': case '(': case ')': case '!': case ':': case ';': case '"': case '\'': case ',': case '.': case '?':
            return 1;
        default:
            return 0;
    }
}

int __palindrome(char * first, char * last)
{
    //Ignore punctuations
    while (punctuation(*first))
        first++;
    while (punctuation(*last))
        last--;

    //Convert to lowercase
    *first |= 32;
    *last  |= 32;
    
    if (first > last)
        return 0;
    else if (first == last)
        return (*first != *last);
    else
        return (*first != *last) + __palindrome(&first[1], &last[-1]);
}

int is_palindrome(char * str)
{
    int i;
    for (i=0; str[i]!='\0'; i++);
    return !__palindrome(&str[0], &str[i-1]);
}

int main()
{
    char str[] = "A man, a plan, a canal - Panama!";
    printf("%d %s", is_palindrome(str), str);
}