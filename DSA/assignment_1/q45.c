#include <stdio.h>

// inverted  : i=inverted, n=not-inverted
// descending: d=descending, a=ascending
// anything else defaults to (n,a)
void pyramid(int n, char inverted, char descending)
{
    if (n<=0)
        return;
    int i;
    if (inverted == 'i' && descending == 'd')
    {
        for (i=n; i>0; i--)
            printf("%d ", i);
        printf("\n");
        pyramid(n-1, inverted, descending);
    }
    else if (inverted == 'i' && descending == 'a')
    {
        for (i=1; i<=n; i++)
            printf("%d ", i);
        printf("\n");
        pyramid(n-1, inverted, descending);
    }
    else if (inverted == 'n' && descending == 'd')
    {
        pyramid(n-1, inverted, descending);
        for (i=n; i>0; i--)
            printf("%d ", i);
        printf("\n");
    }
    else
    {
        pyramid(n-1, inverted, descending);
        for (i=1; i<=n; i++)
            printf("%d ", i);
        printf("\n");
    }
}

int main()
{
    pyramid(4, 'n', 'a'); printf("\n\n");
    pyramid(4, 'n', 'd'); printf("\n\n");
    pyramid(4, 'i', 'a'); printf("\n\n");
    pyramid(4, 'i', 'd'); printf("\n\n");
}