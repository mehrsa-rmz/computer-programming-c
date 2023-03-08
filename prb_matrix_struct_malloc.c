#include <stdio.h>
#include <stdlib.h>

void matrice (int ***a, int *n, int *m)
{
    int i, j;

    printf("Sa se introduca valori pentru n si m, numere naturale:");
    scanf("%d %d", n, m);

    *a = (int**)malloc (*n * sizeof(int*));
    for (i=0; i<*n; i++)
        (*a)[i]=(int*)malloc(*m * sizeof(int));

    printf("Sa se introduca valori pentru matricea a, numere intregi:\n");
    for (i=0; i<*n; i++)
        for (j=0; j<*m; j++)
            {
                printf ("a[%d][%d]=", i, j);
                scanf ("%d", &(*a)[i][j]);
            }
}

void afisare (int **a, int n, int m)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            printf("%5d   ", a[i][j]);
        printf("\n");
    }
}

int simetrie ( int *v, int n)
{
    for (int i=0; i<n/2; i++)
        if(v[i]!=v[n-1-i])
            return 0;
    return 1;
}

int suma (int *v, int n)
{
    int s=0;
    for(int i=0; i<n; i++)
        s+=v[i];
    return s;
}

int main ()
{
    int **a, n, m, *v, i, j, k, nr=0, x, y, z;
    matrice (&a, &n, &m);
    printf("\nMatricea arata astfel:\n");
    afisare (a, n, m);

    for (i=0; i<n; i++)
        for (j=i+1; j<n; j++)
            {
                x=suma(a[i], m);
                y=suma(a[j], m);
                if (y<x)
                    for (k=0; k<m; k++)
                {
                    z=a[i][k];
                    a[i][k]=a[j][k];
                    a[j][k]=z;
                }

            }
    printf("\nDupa ordonarea liniilor in functie de suma elementelor de pe ele, matricea arata astfel:\n");
    afisare (a, n, m);

    v = (int)malloc (n * sizeof(int));

    for (j=0; j<m; j++)
        for (i=0; i<n; i++)
        {
            v[i]=a[i][j];
            if (i==n-1 && simetrie(v,n))
            {
                if (nr==0)
                    printf ("\nIndicii coloanelor simetrice sunt:\n");
                nr ++;
                printf ("%d   ", j);
            }
        }



    if (nr==0) printf("\nNu exista coloane simetrice dupa ordonarea liniilor.");

    return 0;
}
