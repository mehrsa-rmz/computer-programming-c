#include<stdio.h>

int main ()
{
    int n, a[100][100], m, i, j, ok=1, min, max;
    printf("Sa se introduca un numar natural pentru n:");
    scanf ("%d", &n);
    printf("Sa se introduca valorile memorate in matrice, numere intregi:\n");

    for(i=0; i<n; i++)
    for(j=0; j<n; j++)
    {
        printf("a[%d][%d]=", i, j);
        scanf("%d", &a[i][j]);
        if(i==0 && j==0) min=max=a[0][0];
        else
        {
            if(a[i][j]<min)min=a[i][j];
            if(a[i][j]>max)max=a[i][j];
        }
    }

    printf("\nSubpunctul a):\nValoarea minima=%d\nValoarea maxima=%d\n\n", min, max);
    printf("\nSubpunctul b):\nDupa inlocuirea elementelor de pe diagonala principala cu valoarea maxima, matricea arata astfel:\n");
    for(i=0; i<n; i++)
        {for(j=0; j<n; j++)
    {
        if(i==j)a[i][j]=max;
        printf("%5d ", a[i][j]);
    }
    printf("\n");}

    printf("\nSubpunctul c):\nDupa inlocuirea elementelor de sub diagonala secundara cu valoarea minima, matricea arata astfel:\n");
    for(i=0; i<n; i++)
        {for(j=0; j<n; j++)
    {
        if(i+j==n-1)a[i][j]=min;
        printf("%5d ", a[i][j]);
    }
    printf("\n");}


    return 0;
}

