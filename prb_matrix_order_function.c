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

int crescator (int *v, int n)
{
    for(int i=0; i<n-1; i++)
        if(v[i]>v[i+1])
            return 0;
    return 1;
}

int descrescator (int *v, int n)
{
    for(int i=0; i<n-1; i++)
        if(v[i]<v[i+1])
            return 0;
    return 1;
}

int main ()
{
    int a[100][100], n, m, b[100][100], x=0, c, d, i, j;
    matrice (a,&m,&n);
    printf("\nMatricea arata astfel:\n");
    afisare_m (a, m, n);

    for (i=0; i<m; i++)
    {
        c=crescator(a[i], n);
        d=descrescator(a[i], n);
        if(c+d)
        {
            for(j=0; j<n; j++)
                b[x][j]=a[i][j];
            x++;
        }
    }
    printf("\nDupa eliminarea liniilor neordonate, matricea arata astfel:\n");
    afisare_m (b, x, n);

    return 0;
}



