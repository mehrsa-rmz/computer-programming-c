#include<stdio.h>

int main ()
{
    int x=0, y=0, i, j, k=1;
    float v[100], w[100], c;
    printf("Sa se introduca valorile memorate in vector, numere reale, cu spatiu intre ele si sa se incheie sirul de valori cu o paranteza dreapta:\n");
    while (scanf("%f", &v[x]))
        x++;

    for(i=0; i<x; i++)
        for(j=i+1; j<x; j++)
            if (v[i]>v[j])
            {
                c=v[i];
                v[i]=v[j];
                v[j]=c;
            }
    for(i=1; i<x; i++)
        if (v[i]!=v[i-1])
            w[y++]=v[i-1];
    w[y++]=v[x-1];

    printf("\nVectorul are %d valori distincte.", y);
    return 0;
}
