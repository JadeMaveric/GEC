// Write a recursive program to check if a string is a palindrome while only considering letters (ignoring case)
// Copyright (C) 2018  Julius Alphonso

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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