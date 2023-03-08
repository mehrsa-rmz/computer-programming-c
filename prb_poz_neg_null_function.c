#include <stdio.h>

void elemente (int v[100], int nr, int *p, int *n, int *z)
{
    int i;
    *p=0;
    *n=0;
    *z=0;
    for (i=0; i<nr; i++)
    {
        if (v[i]>0) *p+=1;
        if (v[i]<0) *n+=1;
        if (v[i]==0) *z+=1;
    }
}

int main()
{
    int v[100], n, poz, neg, nul, i;

    printf ("Sa se introduca valoarea lui n, numar natural:");
    scanf ("%d", &n);
    printf ("Sa se introduca valorile memorate in vectorul v, numere intregi:\n");
    for (i=0; i<n; i++)
    {
        printf ("v[%d]=", i);
        scanf ("%d", &v[i]);
    }
    elemente (v, n, &poz, &neg, &nul);
    printf ("\nIn vector exista %d elemente pozitive, %d elemente negative si %d elemente nule.", poz, neg, nul);

    return 0;
}

