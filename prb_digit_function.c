#include <stdio.h>

void cifre (int nr, int *nr_cf, int *a, int *b, int *c)
{
    *a=*b=*c=-1; *nr_cf=0;
    if(nr<0) nr=nr*(-1);
    do
    {
        *nr_cf+=1;
        if (*nr_cf==1) *c=nr%10;
        if (*nr_cf==2) *b=nr%10;
        if (*nr_cf==3) *a=nr%10;
        nr/=10;
    }while (nr);
}

int main()
{
    int n, x, y, z, cif;
    printf("Sa se introduca un numar intreg de maxim 3 cifre pentru n:");
    scanf("%d", &n);
    while (n/1000!=0)scanf("%d", &n);
    cifre (n, &cif, &x, &y, &z);
    printf("\nNumarul %d are %d cifre. Acestea sunt:", n, cif);
    if(x>=0)printf("%d  ", x);
    if(y>=0)printf("%d  ", y);
    if(z>=0)printf("%d  ", z);

    return 0;
}
