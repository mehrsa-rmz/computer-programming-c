#include<stdio.h>

int main ()
{
    int n, m, a[100][100], i, j, k, c;
    printf("Sa se introduca un numar natural pentru n si unul pentru m:");
    scanf ("%d %d", &n, &m);
    printf("Sa se introduca valorile memorate in matrice, numere intregi:\n");

    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
        {
            printf("a[%d][%d]=", i, j);
            scanf("%d", &a[i][j]);
        }

    for(i=0; i<n; i+=2)
        for(j=0; j<m; j++)
            if(a[i][j]%2==0)
                for (k=j+1; k<m; k++)
                    if(a[i][k]%2==0)
                        if(a[i][j]>a[i][k])
                        {
                            c=a[i][j];
                            a[i][j]=a[i][k];
                            a[i][k]=c;
                        }


    printf("\nDupa ordonarea crescatoare a elementelor pare de pe liniile pare,matricea arata astfel:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            printf("%5d ", a[i][j]);
        printf("\n");
    }


    return 0;
}

