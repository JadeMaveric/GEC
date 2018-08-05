// Write a recursive function to print pyramids of numbers
// 1        1 2 3 4  4 3 2 1
// 1 2      1 2 3    3 2 1
// 1 2 3    1 2      2 1
// 1 2 3 4  1        1
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

// inverted  : i=inverted, n=not-inverted
// descending: d=descending, a=ascending
// anything else defaults to (n,a)
void pyramid(int n, char inverted, char descending)
{
    if (n<=0)
        return;
    int i;
    if (inverted == 'i' && descending == 'd')
    {
        for (i=n; i>0; i--)
            printf("%d ", i);
        printf("\n");
        pyramid(n-1, inverted, descending);
    }
    else if (inverted == 'i' && descending == 'a')
    {
        for (i=1; i<=n; i++)
            printf("%d ", i);
        printf("\n");
        pyramid(n-1, inverted, descending);
    }
    else if (inverted == 'n' && descending == 'd')
    {
        pyramid(n-1, inverted, descending);
        for (i=n; i>0; i--)
            printf("%d ", i);
        printf("\n");
    }
    else
    {
        pyramid(n-1, inverted, descending);
        for (i=1; i<=n; i++)
            printf("%d ", i);
        printf("\n");
    }
}

int main()
{
    pyramid(4, 'n', 'a'); printf("\n\n");
    pyramid(4, 'n', 'd'); printf("\n\n");
    pyramid(4, 'i', 'a'); printf("\n\n");
    pyramid(4, 'i', 'd'); printf("\n\n");
}