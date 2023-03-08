#include<stdio.h>

int main ()
{
    int a[100][100], b[100][100], m, n, p, q, i, j, k, x, e;
    printf("Sa se introduca doua nurmere naturale pentru m si n:");
    scanf("%d %d", &m, &n);
    printf("Sa se introduca valorile memorate in matricea a, numere intregi:\n");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
        {
            printf("a[%d][%d]=", i, j);
            scanf("%d", &a[i][j]);
        }
    printf("Sa se introduca doua nurmere naturale pentru p si q:");
    scanf("%d %d", &p, &q);
    printf("Sa se introduca valorile memorate in matricea b, numere intregi:\n");
    for(i=0; i<p; i++)
        for(j=0; j<q; j++)
        {
            printf("b[%d][%d]=", i, j);
            scanf("%d", &b[i][j]);
        }
    if (m==p && n==q)
    {
        printf("\nSuma a+b este:\n");
        for(i=0; i<p; i++)
        {
            for(j=0; j<q; j++)
                printf("%5d ", a[i][j]+b[i][j]);
            printf("\n");
        }
    }
    else
        printf("Nu se poate efectua a+b.\n");

    if (n==p)
    {
        printf("\nProdusul a*b este:\n");
        for(i=0; i<m; i++)
        {
            for(j=0; j<q; j++)
            {
                e=0;
                for (k=0; k<n; k++)
                    e+=a[i][k]*b[k][j];
                printf("%5d ",e);
            }

            printf("\n");
        }

    }
    else
        printf("Nu se poate efectua a*b.\n");
    return 0;
}


