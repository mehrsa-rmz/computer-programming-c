#include <stdio.h>

void matrice (int a[100][100], int *m, int *n)
{
    int i, j;

    printf("Sa se introduca valori pentru m si n, numere naturale:");
    scanf("%d %d", m, n);

    printf("Sa se introduca valori pentru matricea a, numere intregi:\n");
    for (i=0; i<*m; i++)
        for (j=0; j<*n; j++)
        {
            printf ("a[%d][%d]=", i, j);
            scanf ("%d", &a[i][j]);
        }
}

void afisare_m (int a[100][100], int m, int n)
{
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
            printf("%5d   ", a[i][j]);
        printf("\n");
    }
}

void ordonare ( int *v, int n)
{
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            if(v[i]>v[j])
            {
                v[i]+=v[j];
                v[j]=v[i]-v[j];
                v[i]=v[i]-v[j];
            }
}

int main()
{
    int  a[100][100], m, n, lin1, lin2, col1, col2, i;

    matrice(a,&m,&n);
    afisare_m(a,m,n);

    for (i=0; i<m; i++)
        ordonare(a[i], n);

    printf("\nDupa ordonarea crescatoare a elementelor fiecarei linii, matricea arata astfel:\n");
    afisare_m(a, m, n);

    return 0;
}



