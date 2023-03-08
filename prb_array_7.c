#include<stdio.h>

int main ()
{
    int n, v[100], cr=1, dcr=1, cst=1;
    printf("Sa se introduca un numar natural pentru n:");
    scanf ("%d", &n);
    printf("Sa se introduca valorile memorate in vector, numere intregi:\n");

    printf("v[0]=");
    scanf("%d", &v[0]);
    for(int i=1; i<n; i++)
    {
        printf("v[%d]=", i);
        scanf("%d", &v[i]);
        if(v[i]!=v[i-1])
            cst=0;
        if(v[i]<v[i-1])
            cr=0;
        if(v[i]>v[i-1])
            dcr=0;
    }

    if (cst)
        printf("\nSirul este constant.");
    else if (cr)
        printf("\nSirul este crescator.");
    else if (dcr)
        printf("\nSirul este descrescator.");
    else
        printf("\nSirul este oarecare.");

    return 0;
}
