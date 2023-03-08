#include<stdio.h>

int main ()
{
    int n, v[100], i, j, prag;
    printf("Sa se introduca un nurmar intreg pentru n:");
    scanf("%d", &n);
    printf("Sa se introduca valorile memorate in vector:\n");
    for(i=0; i<n; i++)
    {
        printf("v[%d]=", i);
        scanf("%d", &v[i]);
    }

    printf("\nSubpunctul a):\n");
    printf("Pragul este:");
    scanf ("%d", &prag);

    printf ("Valorile care depasesc pragul si pozitile lor, afisate sub forma \"[valoare, pozitie]\", sunt:\n");
    for (i=0; i<n; i++)
        if (v[i]>prag)
            printf("[%d,%d] ", v[i], i);

    printf("\n\nSubpunctul b):\n");
    printf("Valorile de pe pozitile pare sunt:\n");
    for (i=0; i<n; i+=2)
        printf("%d  ", v[i]);

    printf("\n\nSubpunctul c):\n");
    for (i=0; i<n; i++)
        if (v[i]==0)
        {
            for (j=i; j<n-1; j++)
                v[j]=v[j+1];
            n--;
            i--;
        }

    printf("Dupa eliminarea valorilor nule, vectorul are %d elemente si arata astfel:\n", n);
    for (i=0; i<n; i++)
        printf ("%d  ", v[i]);

    printf("\n\nSubpunctul d):\n");
    printf("Dupa inlocuirea fiecarei valoare din vector cu numarul sau de divizori, vectorul arata astfel:\n");
    for (i=0; i<n; i++)
    {
        int d=1;
        for (j=2; j<=v[i]; j++)
            if (v[i]%j==0)
                d++;
        v[i]=d;
    }
    for (i=0; i<n; i++)
        printf ("%d  ", v[i]);

    return 0;
}
