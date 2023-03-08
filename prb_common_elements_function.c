#include <stdio.h>

void el_comune (int v[100], int n, int w[100], int m, int t[100], int *k)
{
    int i, j, x, ok=1;
    *k=0;
    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
            if (v[i]==w[j])
            {
                for(x=0; x<*k; x++)
                    if (t[x]==v[i])
                    {
                        ok=0;
                        x=*k;
                    }
                if (ok)
                {
                    t[*k]=v[i];
                    *k+=1;
                }
                ok=1;
                j=m;
            }
}

int main()
{
    int v[100], w[100], t[100], n, m, k, i;

    printf ("Sa se introduca valorile lui n si m, numere naturale:");
    scanf ("%d %d", &n, &m);
    printf ("Sa se introduca valorile memorate in vectorul v, numere intregi:\n");

    for (i=0; i<n; i++)
    {
        printf ("v[%d]=", i);
        scanf ("%d", &v[i]);
    }

    printf ("Sa se introduca valorile memorate in vectorul w, numere intregi:\n");
    for (i=0; i<m; i++)
    {
        printf ("w[%d]=", i);
        scanf ("%d", &w[i]);
    }

    el_comune (v, n, w, m, t, &k);
    if (k==0)
        printf ("\nNu exista elemente comune in cei doi vectori.\n");
    else
    {
        printf ("\nElementele comune ale vectorilor v si w memorate in vectorul t sunt:\n");
        for (i=0; i<k; i++)
            printf ("%d   ", t[i]);
    }

    return 0;
}

