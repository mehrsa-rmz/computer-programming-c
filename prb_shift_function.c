#include <stdio.h>

void permutare (int v[100], int poz, int m)
{
    int j, k, x;
    for (j=1; j<=poz; j++)
    {
        x=v[m-1];
        for (k=m-1; k>=1; k--)
            v[k]=v[k-1];
        v[0]=x;
    }
}

int main()
{
    int v[100][100], n, m, i, j;

    printf ("Sa se introduca valorile lui n si m, numere naturale:");
    scanf ("%d %d", &n, &m);

    printf ("Sa se introduca valorile memorate in matricea v, numere intregi:\n");
    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            printf ("v[%d][%d]=", i, j);
            scanf ("%d", &v[i][j]);
        }
        permutare (v[i], i, m);
    }


    printf ("\nDupa permutarea circulara la dreapta a tuturor liniilor cu un numar de pozitii ce coincide cu indicele liniei, matricea arata astfel:\n");
    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
            printf ("%6d ", v[i][j]);
        printf ("\n");
    }


    return 0;
}

