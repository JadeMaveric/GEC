// Write a recursive function to input and add n numbers
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

int sum_of_nums()
{
    int sum;

    printf("\nEnter number to add: ");
    scanf("%d", &sum);

    if (sum < 0)
        return 0;
    else
        return sum + sum_of_nums();
}

int main()
{
    int sum = sum_of_nums();
    printf("Sum of Numbers is %d", sum);
    return 0;
}