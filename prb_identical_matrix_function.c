#include <stdio.h>

int identitate ( int *v, int n, int *w, int m)
{
    if (n!=m)
        return 0;
    for (int i=0; i<n; i++)
        if (v[i]!=w[i])
            return 0;
    return 1;
}

int main()
{
    int  a[100][100], m, n, b[100][100], x, y, i, j;

    printf ("Sa se introduca valorile lui m si n, numere naturale:");
    scanf ("%d %d", &m, &n);

    printf ("Sa se introduca valorile memorate in matricea a, numere intregi:\n");
    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
        {
            printf ("a[%d][%d]=", i, j);
            scanf ("%d", &a[i][j]);
        }

    printf ("Sa se introduca valorile lui x si y, numere naturale:");
    scanf ("%d %d", &x, &y);

    printf ("Sa se introduca valorile memorate in matricea b, numere intregi:\n");
    for (i=0; i<x; i++)
        for (j=0; j<y; j++)
        {
            printf ("b[%d][%d]=", i, j);
            scanf ("%d", &b[i][j]);
        }

    i=0;
    while (identitate(a[i],m,b[i],x) && i<m)
        i++;

    if (i==m)
        printf ("\nMatricele sunt identice.");
    else
        printf ("\nMatricele nu sunt identice.");


    return 0;
}



