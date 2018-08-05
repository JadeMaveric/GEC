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