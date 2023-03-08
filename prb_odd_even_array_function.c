#include <stdio.h>

void paritate (int v[100], int n, int par[100], int *a, int impar[100], int *b)
{
    int j;
    *a=*b=0;
    for (j=0; j<n; j++)
        if (v[j]%2)
        {
            impar[*b]=v[j];
            *b+=1;
        }
        else
        {
            par[*a]=v[j];
            *a+=1;
        }
}

int main()
{
    int v[100], n, par[100], impar[100], a, b, i;

    printf ("Sa se introduca valoarea lui n, numar natural:");
    scanf ("%d", &n);

    printf ("Sa se introduca valorile memorate in vectorul v, numere naturale:\n");
    for (i=0; i<n; i++)
    {
        printf ("v[%d]=", i);
        scanf ("%d", &v[i]);
    }

    paritate (v,n,par,&a,impar,&b);

    printf ("\n\nVectorul de elemente pare contine elementele:\n");
    for (i=0; i<a; i++)
        printf("%d   ", par[i]);

    printf ("\nVectorul de elemente impare contine elementele:\n");
    for (i=0; i<b; i++)
        printf("%d   ", impar[i]);


    return 0;
}


