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
    int nums[] = {2, 6, 10, 3, 45, 21, 32, 64};
    int size = sizeof(nums)/sizeof(nums[0]);
    int i;
    
    for (i=0; i<size; i++)
        printf("%d/%d\t%d\n", nums[i], nums[(2*i+3)%size], quotient(nums[i], nums[(2*i+3)%size]));
        
    return 0;
}