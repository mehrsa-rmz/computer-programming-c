#include<stdio.h>

int main ()
{
    int n, v[100], p, poz[100], i, j, x;
    printf("Sa se introduca un numar natural pentru n:");
    scanf ("%d", &n);
    printf("Sa se introduca valorile memorate in primul vector, numere intregi:\n");

    for(i=0; i<n; i++)
       {
       printf("v[%d]=", i);
       scanf("%d", &v[i]);
       }

    printf("Sa se introduca un numar natural pentru p:");
    scanf ("%d", &p);
    printf("Sa se introduca valorile memorate in al doilea vector, numere naturale mai mici decat n:\n");

    for(i=0; i<p; i++)
       {
       printf("poz[%d]=", i);
       scanf("%d", &poz[i]);
       while (poz[i]<0 || poz[i]>=n)scanf("%d", &poz[i]);
       }

    printf("\nValorile din vectorul v ce se afla in pozitiile specificate de valorile din vectorul poz sunt:\n");
    for(i=0; i<p; i++) printf("%d   ", v[poz[i]]);

    return 0;
}

