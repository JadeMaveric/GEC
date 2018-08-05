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