#include <stdio.h>

int perechi (int v[100], int n)
{
    int j, nr=0, x;
    for (j=1; j<n; j++)
        if (v[j]==v[j-1])
            nr++;
    return nr;
}

int main()
{
    int v[100], n, i, p;

    printf ("Sa se introduca valoarea lui n, numar natural:");
    scanf ("%d", &n);

    printf ("Sa se introduca valorile memorate in vectorul v, numere intregi:\n");
    for (i=0; i<n; i++)
    {
        printf ("v[%d]=", i);
        scanf ("%d", &v[i]);
    }

    p=perechi (v, n);


    printf ("\nIn vector exista %d grupuri de cate 2 numere consecutive egale.", p);

    return 0;
}


