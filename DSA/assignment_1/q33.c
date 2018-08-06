// Write a recursive function to find Binomial Coefficient - nCk.
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

int C(int n, int k)
{
    if (k == 0)
        return 1;
    else if (n == k)
        return 1;
    else
        return C(n-1, k-1) + C(n-1, k);
}

int main()
{
    int nums[] = {2, 6, 10, 3, 0, 1, 6, 2, };
    int size = sizeof(nums)/sizeof(nums[0]);
    int i;
    
    for (i=0; i<size; i++)
        printf("%dC%d\t%d\n", nums[i], nums[(2*i+3)%size], C(nums[i], nums[(2*i+3)%size]));
        
    return 0;
}