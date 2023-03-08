#include<stdio.h>

int main ()
{
     int n, v[100], i[100], p[100], j, x=0, y=0;
    printf("Sa se introduca un nurmar intreg pentru n:");
    scanf("%d", &n);
    printf("Sa se introduca valorile memorate in vector:\n");
    for(j=0; j<n; j++)
    {
        printf("v[%d]=", j);
        scanf("%d", &v[j]);
        if (v[j]%2) i[x++]=v[j];
        else p[y++]=v[j];
    }
    printf("\nVectorul cu valori pare contine elementele:\n");
    for (j=0; j<y; j++)
        printf("%d  ", p[j]);
    printf("\n\nVectorul cu valori impare contine elementele:\n");
    for (j=0; j<x; j++)
        printf("%d  ", i[j]);


 return 0;
}
