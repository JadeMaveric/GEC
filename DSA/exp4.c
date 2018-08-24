#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define reset "\033[0m"
#define red   "\033[31m"
#define green "\033[32m"
#define bold  "\033[1m"

void bubble_sort( char * X )
{
    int N;
    for(N = 0; X[N]!='\0'; N++);

    int i;
    for(i = 0; i < N; i++)
    {
        int j;
        for(j = 0; j < N - 1; j++)
        {
            if(X[j] > X[j+1])
            {
                X[j]   = X[j] + X[j+1];
                X[j+1] = X[j] - X[j+1];
                X[j]   = X[j] - X[j+1];

                for(int k = 0; k < j; k++)
                    printf("%c ", X[k]);
                printf("%s%c%s ", red, X[j], reset);
                printf("%s%c%s ", green, X[j+1], reset);
                for(int k = j+2; k < N; k++)
                    printf("%c ", X[k]);
                printf("\n");
            }
        }
        printf("\n");
    }
}

void insertion_sort(char *X) {
    int N;
    for(N = 0; X[N]!='\0'; N++);

    int i, j;
    for (i=1; i<N; i++) {
        for (j=0; j<N; j++) {
            if (X[i] < X[j]) {
                int k;
                char temp = X[i];
                
                //verbose printing
                for(k=0; k<j; k++)
                    printf("%c", X[k]);
                printf("%s", bold);
                for(k=j; k<i; k++)
                    printf("%c", X[k]);
                printf("%s%c%s", green, X[i], reset);
                for(k=i+1; k<N; k++)
                    printf("%c", X[k]);
                printf("\n");

                //insert i
                for (k=i; k>j; k--) {
                    X[k] = X[k-1];
                }
                X[j] = temp;
            }
        }
    }
}

void selection_sort(char * X)
{
    int i, j;
    int large;

    int N;
    for(N=0; X[N]!='\0'; N++);

    char verbose = 'V';

    for(i=0; i<N; i++)
    {
        // Verbose: Output Array
        if(verbose == 'V')
        {
            int j;
            printf("Pass %d:\n", i+1);
            for(j=0; j<N; j++)
            {
                printf("%d ", X[j]);
            }
            printf("\n");
        }

        for(j=i+1; j<N; j++)
        {
            //Ascending Sort
            if(X[j] < X[i])
            {
                // Verbose: Output modifications
                if(verbose == 'V')
                {
                    int k;
                    for( k=0; k<N; k++)
                    {
                        if( k == i )
                            printf("\033[1;31m%d \033[0m", X[k]);
                        else if( k == j )
                            printf("\033[1;32m%d \033[0m", X[k]);
                        else
                            printf("%d ", X[k]);
                    }
                    printf("\n");

                }

                X[j]  = X[j] + X[i];
                X[i]  = X[j] - X[i];
                X[j]  = X[j] - X[i];
            }
        }
    }
}

void shell_sort(int * X, int N) {
    int n;
    for(n=N/2; n>0; n/=2) {
        int offset;
        for(offset=0; offset<n; offset++) {
            int i;
            for(i=offset; i<N; i+=n) {
                int j;
                for(j=2*offset; j<N; j+=n) {
                    if(X[j] < X[i]) {
                        X[j]  = X[j] + X[i];
                        X[i]  = X[j] - X[i];
                        X[j]  = X[j] - X[i];
                    }
                }
            }
        }
    }
}

void merge_sort(int * X, int N) {
    if (N == 1) return;

    int N_1, N_2;
    N_1 = N/2;
    N_2 = N/2.0f + 0.5f;

    merge_sort(X, N_1);
    merge_sort(&X[N/2], N_2);

    // make temporary arrays
    int * arr_1 = malloc(N_1 * Nof(int));
    int * arr_2 = malloc(N_2 * Nof(int));

    int i;
    for(i=0; i<N_1; i++) {
        arr_1[i] = X[i];
    }
    for(i=0; i<N_2; i++) {
        arr_2[i] = X[N/2 + i];
    }

    // merge temp arrays
    int a=0, b=0;
    for(i=0; i<N; i++) {
        if (a >= N_1) {
            X[i] = arr_2[b++];
        }
        else if (b >= N_2) {
            X[i] = arr_1[a++];
        }
        else if (arr_1[a] < arr_2[b]) {
            X[i] = arr_1[a++];
        }
        else {
            X[i] = arr_2[b++];
        }
    }

    free(arr_1);
    free(arr_2);
}    

int main(int argc, char ** argv) {
    // if(argc < 3) {
    //     printf("USAGE: %s sort_type [data]\n", argv[0]);
    //     return 1;
    // }

    int * X;
    int i, N;
    if(argc < 3) {
        printf("Enter no of elements: ");
        scanf("%d", &N);
        X = malloc(N * Nof(int));
        for(i=0; i<N; i++) {
            printf("Enter element %d: ", i);
            scanf("%d", &X[i]);
        }
           
    }

    if (strcmp(argv[1], "bubble") == 0) {
        bubble_sort(argv[2]);
        printf("\n%s\n", argv[2]);
    }
    else if (strcmp(argv[1], "insertion") == 0) {
        insertion_sort(argv[2]);
        printf("\n%s\n", argv[2]);
    }
    else if (strcmp(argv[1], "selection") == 0) {
        selection_sort(argv[2]);
        printf("\n%s\n", argv[2]);
    }
    else if (strcmp(argv[1], "shell") == 0) {
        shell_sort(X, N);
        for(i=0; i<N; i++)
            printf("%d", X[i]);
        printf("\n");
    }
    else if (strcmp(argv[1], "merge") == 0) {
        merge_sort(X, N);
        for(i=0; i<N; i++)
            printf("%d", X[i]);
        printf("\n");
    }
    else if (strcmp(argv[1], "quick") == 0) {
        
        for(i=0; i<N; i++)
            printf("%d", X[i]);
        printf("\n");
    }
    else {
        
    }
    return 0;
}