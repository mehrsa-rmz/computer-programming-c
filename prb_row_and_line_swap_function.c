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

void interschimbare ( int *v, int *w, int n)
{
    for (int i=0; i<n; i++)
    {
        v[i]+=w[i];
        w[i]=v[i]-w[i];
        v[i]=v[i]-w[i];
    }
}

int main()
{
    int  a[100][100], v[100], w[100], m, n, lin1, lin2, col1, col2, i;

    matrice(a,&n,&m);
    afisare_m(a,n,m);

    printf ("\nSa se introduca 2 numere naturale intre 0 si %d inclusiv, indicii liniilor care vor fi interschimbate:", n-1);
    scanf("%d %d", &lin1, &lin2);
    interschimbare (a[lin1], a[lin2], m);

    printf ("\nSa se introduca 2 numere naturale intre 0 si %d inclusiv, indicii coloanelor care vor fi interschimbate:", m-1);
    scanf("%d %d", &col1, &col2);
    for (i=0; i<n; i++)
    {
        v[i]=a[i][col1];
        w[i]=a[i][col2];
    }
    interschimbare (v, w, n);
    for (i=0; i<n; i++)
    {
        a[i][col1]=v[i];
        a[i][col2]=w[i];
    }

    printf("\nDupa modificari, matricea arata astfel:\n");
    afisare_m(a, n, m);

    return 0;
}



