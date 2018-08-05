#include <stdio.h>

int sorted(int * arr, int size)
{
    if (size == 2)
        return arr[0]<=arr[1] ? 1 : 0;
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