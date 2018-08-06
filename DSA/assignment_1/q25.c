// Write a recursive function to find if an array is in strict ascending order or not.
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

int sorted(int * arr, int size)
{
    if (size == 2)
        return arr[0]<arr[1] ? 1 : 0;
    else if (arr[0] > arr[1])
        return 0;
    else
        return sorted(++arr, size-1);
}

int main()
{
    int nums[] = {2, 5, 7, 9, 10, 15 , 21};
    int size = sizeof(nums)/sizeof(nums[0]);
    printf("%d", sorted(nums, size));
    return 0;
}