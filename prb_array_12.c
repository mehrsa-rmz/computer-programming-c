#include<stdio.h>

int main ()
{
    int n, v[100], i, j, x, poz=0;
    printf("Sa se introduca un numar natural pentru n:");
    scanf ("%d", &n);
    printf("Sa se introduca valorile memorate in vector, numere intregi ordonate crescator:\n");

    for(i=0; i<n; i++)
       {
       printf("v[%d]=", i);
       scanf("%d", &v[i]);
       if(i>0)
        while(v[i]<v[i-1])scanf("%d", &v[i]);
       }

    printf("Sa se introduca un numar intreg pentru a fi inserat in vector:");
    scanf ("%d", &x);

    while (v[poz]<x)poz++;
    for(i=n; i>poz; i--) v[i]=v[i-1];
    v[poz]=x;

    printf("\nDupa inserarea noului termen, vectorul arata astfel:\n");
    for(i=0; i<=n; i++) printf("%d   ", v[i]);


    return 0;
}

