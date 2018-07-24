#include <stdio.h>

void bubble_sort( int * X, int size )
{
    int i;
    for(i = 0; i < size; i++)
    {
        int j;
        for(j = 0; j < size - 1; j++)
        {
            if(X[j] > X[j+1])
            {
                X[j]   = X[j] + X[j+1];
                X[j+1] = X[j] - X[j+1];
                X[j]   = X[j] - X[j+1];

                for(int k = 0; k < j; k++)
                    printf("%d ", X[k]);
                printf("\033[1;31m%d \033[0m", X[j]);
                printf("\033[1;32m%d \033[0m", X[j+1]);
                for(int k = j+2; k < size; k++)
                    printf("%d ", X[k]);
                printf("\n");
            }
        }
        printf("\n");
    }
}

int main()
{
    int A[] = {49, 66, 73, 80, 75, 75, 34, 70, 96, 95};
    int size = 10;

    bubble_sort(A, size);

    return 0;
}