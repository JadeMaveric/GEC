#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define reset "\033[0m"
#define red   "\033[31m"
#define green "\033[32m"
#define bold  "\033[1m"

void bubble_sort( char * X )
{
    int size;
    for(size = 0; X[size]!='\0'; size++);

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
                    printf("%c ", X[k]);
                printf("%s%c%s ", red, X[j], reset);
                printf("%s%c%s ", green, X[j+1], reset);
                for(int k = j+2; k < size; k++)
                    printf("%c ", X[k]);
                printf("\n");
            }
        }
        printf("\n");
    }
}

void insertion_sort(char *X) {
    int size;
    for(size = 0; X[size]!='\0'; size++);

    int i, j;
    for (i=1; i<size; i++) {
        for (j=0; j<size; j++) {
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
                for(k=i+1; k<size; k++)
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

void selection_sort(char * list)
{
    int i, j;
    int large;

    int size;
    for(size=0; list[size]!='\0'; size++);

    char verbose = 'V';

    for(i=0; i<size; i++)
    {
        // Verbose: Output Array
        if(verbose == 'V')
        {
            int j;
            printf("Pass %d:\n", i+1);
            for(j=0; j<size; j++)
            {
                printf("%d ", list[j]);
            }
            printf("\n");
        }

        for(j=i+1; j<size; j++)
        {
            //Ascending Sort
            if(list[j] < list[i])
            {
                // Verbose: Output modifications
                if(verbose == 'V')
                {
                    int k;
                    for( k=0; k<size; k++)
                    {
                        if( k == i )
                            printf("\033[1;31m%d \033[0m", list[k]);
                        else if( k == j )
                            printf("\033[1;32m%d \033[0m", list[k]);
                        else
                            printf("%d ", list[k]);
                    }
                    printf("\n");

                }

                list[j]  = list[j] + list[i];
                list[i]  = list[j] - list[i];
                list[j]  = list[j] - list[i];
            }
        }
    }
}

void shell_sort(int * list, int size) {
    int n;
    for(n=size/2; n>0; n/=2) {
        int offset;
        for(offset=0; offset<n; offset++) {
            int i;
            for(i=offset; i<size; i+=n) {
                int j;
                for(j=2*offset; j<size; j+=n) {
                    if(list[j] < list[i]) {
                        list[j]  = list[j] + list[i];
                        list[i]  = list[j] - list[i];
                        list[j]  = list[j] - list[i];
                    }
                }
            }
        }
    }
}

void merge_sort(int * list, int size) {
    if (size == 1) return;

    int size_1, size_2;
    size_1 = size/2;
    size_2 = size/2.0f + 0.5f;

    merge_sort(list, size_1);
    merge_sort(&list[size/2], size_2);

    // make temporary arrays
    int * arr_1 = malloc(size_1 * sizeof(int));
    int * arr_2 = malloc(size_2 * sizeof(int));

    int i;
    for(i=0; i<size_1; i++) {
        arr_1[i] = list[i];
    }
    for(i=0; i<size_2; i++) {
        arr_2[i] = list[size/2 + i];
    }

    // merge temp arrays
    int a=0, b=0;
    for(i=0; i<size; i++) {
        if (a >= size_1) {
            list[i] = arr_2[b++];
        }
        else if (b >= size_2) {
            list[i] = arr_1[a++];
        }
        else if (arr_1[a] < arr_2[b]) {
            list[i] = arr_1[a++];
        }
        else {
            list[i] = arr_2[b++];
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

    int * list;
    int i, size;
    if(argc < 3) {
        printf("Enter no of elements: ");
        scanf("%d", &size);
        list = malloc(size * sizeof(int));
        for(i=0; i<size; i++) {
            printf("Enter element %d: ", i);
            scanf("%d", &list[i]);
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
        shell_sort(list, size);
        for(i=0; i<size; i++)
            printf("%d", list[i]);
        printf("\n");
    }
    else if (strcmp(argv[1], "merge") == 0) {
        merge_sort(list, size);
        for(i=0; i<size; i++)
            printf("%d", list[i]);
        printf("\n");
    }
    else if (strcmp(argv[1], "quick") == 0) {
        
        for(i=0; i<size; i++)
            printf("%d", list[i]);
        printf("\n");
    }
    else {
        
    }
    return 0;
}