#include <stdio.h>

void vector (int *v, int m)
{
    int i;

    printf("Sa se introduca valori pentru vectorul v, numere intregi:\n");
    for (i=0; i<m; i++)
    {
        printf ("v[%d]=", i);
        scanf ("%d", &v[i]);
    }
}

void afisare_v (int *v, int n)
{
    for (int i=0; i<n; i++)
        printf("%d   ", v[i]);
    printf("\n");
}

int main ()
{
    int *v, m, i, j;
    printf("Sa se introduca o valoare pentr m, numar natural:");
    scanf("%d", &m);
    v=(int *) calloc (m, sizeof(int));
    vector (v, m);
    afisare_v (v, m);
    free(v);

    return 0;
}



