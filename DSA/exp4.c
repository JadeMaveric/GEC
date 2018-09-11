#include <stdio.h>
#include <stdlib.h>

#define reset "\033[0m"
#define red   "\033[31m"
#define green "\033[32m"
#define bold  "\033[1m"

int strcmp(const char *str1, const char *str2) {
    int i=0, diff=0;
    while ( (diff==0) && (str1[i]!='\0') && (str2[i]!='\0') ) {
        diff = str1[i] - str2[i];
        i++;
    }
    return diff;
}

int _str_to_int(char * str) {
    int num = 0, i;
    for(i=0; str[i]!='\0'; i++) {
        num = num * 10;
        num = num + (int)str[i] - (int)'0';
    }
    return num;
}

void _get_list(char ** arg, int * list, int size) {
    int i;
    for(i=0; i<size; i++) {
        list[i] = _str_to_int(arg[i]);
        //printf("%s->%d ", arg[i], list[i]);
    }
}

void bubble_sort(char ** X, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        int j;
        for(j = 0; j < size - 1; j++)
        {
            if(strcmp(X[j], X[j+1]) > 0)
            {
                char * temp = X[j+1];
                X[j+1] = X[j];
                X[j]   = temp;
            }
        }
    }
}

void insertion_sort(char ** X, int size) {
    int i, j;
    for (i=1; i<size; i++) {
        for (j=0; j<size; j++) {
            if (strcmp(X[i], X[j]) > 0) {
                int k;
                char * temp = X[i];

                //insert i
                for (k=i; k>j; k--) {
                    X[k] = X[k-1];
                }
                X[j] = temp;
            }
        }
    }
}

void selection_sort(char ** list, int size)
{
    int i, j;
    int large;

    for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            //Ascending Sort
            if(strcmp(list[j], list[i]) < 0)
            {
                char * temp = list[i];
                list[i]  = list[j];
                list[j]  = temp;
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

int _partition(int * list, int low, int high) {
    int pivot = 0;

    while (low < high) {
        for (; list[low] <= list[pivot]; low++);
        for (; list[high] > list[pivot]; high--);

        if (low < high) {
            int temp   = list[high];
            list[high] = list[low];
            list[low]  = temp;
        }
        else {
            int temp    = list[high];
            list[high]  = list[pivot];
            list[pivot] = temp;
            return high;
        }
    }
}

void quick_sort(int * list, int size) {
    if(size<=1) return;

    int piv = _partition(list, 0, size-1);
    quick_sort(&list[0], piv);
    quick_sort(&list[piv+1], size-piv-1);
}

int main(int argc, char ** argv) {
    if(argc < 3) {
        printf("USAGE: %s sort_type [data]\n", argv[0]);
        return 1;
    }

    int * list = NULL;
    int i, size = argc-2;

    if (strcmp(argv[1], "bubble") == 0) {
        bubble_sort(&argv[2], size);
        printf("\n");
        for(i=2; i<argc; i++)
            printf("%s ", argv[i]);
        printf("\n");
    }
    else if (strcmp(argv[1], "insertion") == 0) {
        insertion_sort(&argv[2], size);
        printf("\n");
        for(i=2; i<argc; i++)
            printf("%s ", argv[i]);
        printf("\n");
    }
    else if (strcmp(argv[1], "selection") == 0) {
        selection_sort(&argv[2], size);
        printf("\n");
        for(i=2; i<argc; i++)
            printf("%s ", argv[i]);
        printf("\n");
    }
    else if (strcmp(argv[1], "shell") == 0) {
        list = malloc(size * sizeof(int));
        _get_list(&argv[2], list, size);
        shell_sort(list, size);
        for(i=0; i<size; i++)
            printf("%d ", list[i]);
        printf("\n");
    }
    else if (strcmp(argv[1], "merge") == 0) {
        list = malloc(size * sizeof(int));
        _get_list(&argv[2], list, size);
        merge_sort(list, size);
        for(i=0; i<size; i++)
            printf("%d ", list[i]);
        printf("\n");
    }
    else if (strcmp(argv[1], "quick") == 0) {
        list = malloc(size * sizeof(int));
        _get_list(&argv[2], list, size);
        quick_sort(list, size);
        for(i=0; i<size; i++)
            printf("%d ", list[i]);
        printf("\n");
    }
    else {
        printf("Invalid Option %s", argv[1]);
    }
    
    if(list!= NULL) free(list);
    return 0;
}