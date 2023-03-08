#include<stdio.h>

int main ()
{
    int n, v[100], i, j, k, p, x;
    printf("Sa se introduca un nurmar natural pentru n:");
    scanf("%d", &n);
    printf("Sa se introduca valorile memorate in vector, numere intregi:\n");
    for(i=0; i<n; i++)
    {
        printf("v[%d]=", i);
        scanf("%d", &v[i]);
    }
    printf("Sa se introduca un nurmar natural pentru p:");
    scanf("%d", &p);
    for(k=1; k<=p; k++)
    {
        x=v[n-1];
        for(i=n-1; i>0; i--) v[i]=v[i-1];
        v[0]=x;
    }
    printf ("\n\nDupa ce a fost permutat cu %d pozitii spre dreapta, vectorul arata astfel:\n", p);
    for(i=0; i<n; i++) printf("%d   ", v[i]);

    for(k=1; k<=2*p; k++)
    {
        x=v[0];
        for(i=0; i<n-1; i++) v[i]=v[i+1];
        v[n-1]=x;
    }
    printf ("\n\nDupa ce a fost permutat cu %d pozitii spre stanga, vectorul arata astfel:\n", p);
    for(i=0; i<n; i++) printf("%d   ", v[i]);

    return 0;
}
