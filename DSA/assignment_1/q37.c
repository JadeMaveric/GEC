// Write a recursive to reverse a string.
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