#include<stdio.h>

int main ()
{
    int n, v[100], m, i, j, ok=1, met;
    printf("Sa se introduca un numar natural pentru n:");
    scanf ("%d", &n);
    printf("Sa se introduca valorile memorate vector, numere intregi:\n");

    for(i=0; i<n; i++)
    {
        printf("v[%d]=", i);
        scanf("%d", &v[i]);
    }

    printf("Sa se introduca 1 (selection sort) sau 2 (bubble sort), pentru a hotari metoda de sortare: ");
    scanf ("%d", &met);

    if(met==1)
    {
        for(i=0; i<n; i++)
            for(j=i+1; j<n; j++)
                if (v[i]<v[j])
                {
                    m=v[i];
                    v[i]=v[j];
                    v[j]=m;
                }
    }

    else
        while (ok)
        {
            ok=0;
            for (i=0; i<n-1; i++)
                if(v[i]<v[i+1])
                {
                    ok=1;
                    m=v[i];
                    v[i]=v[i+1];
                    v[i+1]=m;
                }
        }

    for(i=0; i<n; i++)
        printf ("%d   ", v[i]);


    return 0;
}

