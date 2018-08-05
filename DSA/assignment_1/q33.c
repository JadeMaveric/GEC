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
    int nums[] = {2, 6, 10, 3, 0, 1, 6, 2, 3};
    int size = sizeof(nums)/sizeof(nums[0]);
    int i;
    
    for (i=0; i<size; i++)
        printf("%dC%d\t%d\n", nums[i], nums[(2*i+3)%size], C(nums[i], nums[(2*i+3)%size]));
        
    return 0;
}