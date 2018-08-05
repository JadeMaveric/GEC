// Write a recursive program that finds whether a number is perfect or not
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

int sum_of_factors(int num, int factor)
{
    if (num == factor)
        return 0;
    else if (num % factor == 0)
        return factor + sum_of_factors(num, factor+1);
    else
        return sum_of_factors(num, factor+1);
}

int is_perfect(int num)
{
    if (num%2 != 0)
        return 0;
    else if (num == sum_of_factors(num, 1))
        return 1;
    else
        return 0;
}

int main()
{
    int nums[] = {2, 6, 24, 28, 32, 496, 8128, 8129};
    int size = sizeof(nums)/sizeof(nums[0]);
    int i;
    
    for (i=0; i<size; i++)
        printf("%d\t%d\n", nums[i], is_perfect(nums[i]));
        
    return 0;
}