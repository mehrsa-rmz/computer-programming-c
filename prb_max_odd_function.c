#include <stdio.h>

int max_imp (int v[100], int n)
{
    int j, max=0;
    for (j=0; j<n; j++)
        if (v[j]%2 && v[j]>max)
            max=v[j];
    return max;
}

int main()
{
    int v[100], n, i, x;

    printf ("Sa se introduca valoarea lui n, numar natural:");
    scanf ("%d", &n);

    printf ("Sa se introduca valorile memorate in vectorul v, numere naturale:\n");
    for (i=0; i<n; i++)
    {
        printf ("v[%d]=", i);
        scanf ("%d", &v[i]);
    }

    x=max_imp(v, n);


    if (x)
        printf ("\nValoarea impara maxima din vector este %d.", x);
    else
        printf ("\nNu exista elemente impare.");

    return 0;
}


