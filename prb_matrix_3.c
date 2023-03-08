#include<stdio.h>

int main ()
{
    int a[100][100], m, n, i, j, c1, c2, x;
    printf("Sa se introduca doua nurmere naturale pentru m si n:");
    scanf("%d %d", &m, &n);
    printf("Sa se introduca valorile memorate in matrice, numere intregi:\n");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
        {
            printf("a[%d][%d]=", i, j);
            scanf("%d", &a[i][j]);
        }
    printf("Sa se introduca doua nurmere naturale pentru c1 si c2:");
    scanf("%d %d", &c1, &c2);

    for(i=0; i<m; i++)
        {
          x=a[i][c1]; a[i][c1]=a[i][c2]; a[i][c2]=x;
        }
    printf("\nDupa interschimbarea coloanelor %d si %d, matricea arata astfel:\n", c1, c2);
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
                printf("%5d ", a[i][j]);
            printf("\n");
        }
    return 0;
}


