#include <stdio.h>

void matrice (int a[100][100], int *n, int *m)
{
    int i, j;

    printf("Sa se introduca valori pentru n si m, numere naturale:");
    scanf("%d %d", n, m);

    printf("Sa se introduca valori pentru matricea a, numere intregi:\n");
    for (i=0; i<*n; i++)
        for (j=0; j<*m; j++)
        {
            printf ("a[%d][%d]=", i, j);
            scanf ("%d", &a[i][j]);
        }
}

void afisare_m (int a[100][100], int n, int m)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            printf("%5d   ", a[i][j]);
        printf("\n");
    }
}

void vector (int v[100], int *x)
{
    int i, j;

    printf("Sa se introduca o valoare pentru x, numar natural:");
    scanf("%d", x);

    printf("Sa se introduca valori pentru vectorul v, numere intregi:\n");
    for (i=0; i<*x; i++)
    {
        printf ("v[%d]=", i);
        scanf ("%d", &v[i]);
    }
}

void afisare_v (int v[100], int n)
{
    for (int i=0; i<n; i++)
        printf("%d   ", v[i]);
    printf("\n");
}

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
    int  a[100][100], m, n, v[100], x, i, j, nr=0, lin;

    matrice(a,&n,&m);
    afisare_m(a,n,m);

    vector (v,&x);
    afisare_v(v,x);

    if(m==x)
        for(i=0; i<n; i++)
            if (identitate(a[i],m,v,x))
            {
                if (!nr)
                    printf("\nLiniile matricei care sunt identice cu vectorul v au indicii:\n");
                nr++;
                printf("%d   ", i);
            }
    if(nr==0)
    {
        if(m!=x)
            printf("\nIn matrice nu exista linii identice cu vectorul, deoarece nu sunt compatibile ca numar de elemente.");
        else
        {
            printf ("\nIn matrice nu exista linii identice cu vectorul.\nSa se introduca un numar natural intre 0 si %d inclusiv, indicele liniei care va fi inlocuita cu elementele vectorului:", n-1);
            scanf ("%d", &lin);
            for (i=0; i<m; i++)
                a[lin][i]=v[i];
            afisare_m(a, n, m);
        }
    }
    return 0;
}



