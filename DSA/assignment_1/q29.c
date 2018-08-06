// Write a recursive function to find the qoutient when a positive integer is divided by another positive intiger.
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

int quotient(int numerator, int denominator)
{
    if (numerator < denominator)
        return numerator;
    else if (numerator == denominator)
        return 0;
    else
        return quotient(numerator-denominator, denominator);
}

int main()
{
    int nums[] = {2, 6, 10, 3, 45, 21, 1};
    int size = sizeof(nums)/sizeof(nums[0]);
    int i;
    
    for (i=0; i<size; i++)
        printf("%d/%d\t%d\n", nums[i], nums[(2*i+3)%size], quotient(nums[i], nums[(2*i+3)%size]));
        
    return 0;
}