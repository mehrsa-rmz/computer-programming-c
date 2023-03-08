#include<stdio.h>

int main ()
{
    int n, a[100][100], i, j, k, x;
    printf("Sa se introduca un nurmar natural pentru n:");
    scanf("%d", &n);
    printf("Sa se introduca valorile memorate in matrice, numere intregi:\n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            printf("a[%d][%d]=", i, j);
            scanf("%d", &a[i][j]);
        }
    printf("\nSubpunctul a):\n");
    printf("Valorile matricei sunt:\n");

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%5d ", a[i][j]);
        printf("\n");
    }

    printf("\nSubpunctul b):\n");
    printf("Valorile de pe diagonala principala a matricei sunt:\n");
    for(i=0; i<n; i++)
        printf ("%d   ", a[i][i]);
    printf("\nValorile de pe diagonala secundara a matricei sunt:\n");
    for(i=0; i<n; i++)
        printf ("%d   ", a[i][n-i-1]);

    printf("\n\nSubpunctul c):\n");
    printf("Valorile din triunghul superior al matricei sunt:\n");
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
            printf("%5d ", a[i][j]);
        printf("\n");
    }
    printf("Valorile din triunghul inferior al matricei sunt:\n");
    for(i=1; i<n; i++)
    {
        for(j=0; j<i; j++)
            printf("%5d ", a[i][j]);
        printf("\n");
    }

    printf("\nSubpunctul d):\n");
    printf("Valorile de pe conturul matricei sunt:\n");
    for (i=0; i<n; i++)
        printf("%5d ", a[0][i]);
    printf("\n");
    for(i=1; i<n-1; i++)
    {
        printf("%5d ", a[i][0]);
        for(j=1; j<n-1; j++)
            printf("      ");
        printf("%5d \n", a[i][n-1]);
    }
    for (i=0; i<n; i++)
        printf("%5d ", a[n-1][i]);
    printf("\nValorile din interiorul conturului matricei sunt:\n");
    for(i=1; i<n-1; i++)
    {
        for(j=1; j<n-1; j++)
            printf("%5d ", a[i][j]);
        printf("\n");
    }


    return 0;
}
