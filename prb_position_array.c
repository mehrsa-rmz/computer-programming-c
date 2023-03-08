#include <stdio.h>

void poz_min (int v[100], int n, int min, int x[100], int *k)
{
    int i;
    *k=0;
    for (i=0; i<n; i++)
        if (v[i]==min)
        {
            x[*k]=i;
            *k+=1;
        }
}

int main()
{
    int v[100], x[100], n, k, i, el_min;

    printf ("Sa se introduca valoarea lui n, numar natural:");
    scanf ("%d", &n);

    printf ("Sa se introduca valorile memorate in vectorul v, numere intregi:\n");
    for (i=0; i<n; i++)
    {
        printf ("v[%d]=", i);
        scanf ("%d", &v[i]);
        if (i==0)
            el_min=v[0];
        else if (v[i]<el_min)
            el_min=v[i];
    }

    poz_min (v, n, el_min, x, &k);

    printf ("\nPozitiile pe care se afla elementul minim al vectorului v, memorate in vectorul x, sunt:\n");
    for (i=0; i<k; i++)
        printf ("%d   ", x[i]);

    return 0;
}

