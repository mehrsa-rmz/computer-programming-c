#include <stdio.h>

void eliminare (int v[100], int *n, int el1)
{
    int i, j;
    for (i=0; i<*n; i++)
        if (v[i]==el1)
        {
            for(j=i; j<*n-1; j++)
                v[j]=v[j+1];
            *n-=1;
        }
}

int main()
{
    int v[100], n, el_1, i;

    printf ("Sa se introduca valoarea lui n, numar natural:");
    scanf ("%d", &n);

    printf ("Sa se introduca valorile memorate in vectorul v, numere intregi:\n");
    for (i=0; i<n; i++)
    {
        printf ("v[%d]=", i);
        scanf ("%d", &v[i]);
    }
    el_1=v[0];

    eliminare (v, &n, el_1);

    printf ("\nDupa eliminarea tuturor aparitiilor primului element, vectorul are %d elemente si arata astfel:\n", n);
    for (i=0; i<n; i++)
        printf ("%d   ", v[i]);

    return 0;
}

