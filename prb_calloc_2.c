#include <stdio.h>

void aloc_cit (int *m, int **w)
{
    int i;
    printf ("Sa se introduca o valoare pentru m, numar natural:");
    scanf("%d", m);

    *w=(int *) calloc (*m, sizeof(int));

    printf ("Sa se introduca valorile memorate in vectorul w, numere naturale:\n");
    for(i=0; i<*m; i++)
    {
        printf("w[%d]=", i);
        scanf("%d", &(*w)[i]);
    }
}

int main()
{
    int n, *v, m, *w, i;

    printf ("Sa se introduca o valoare pentru n, numar natural:");
    scanf("%d", &n);

    v=(int *) calloc (n, sizeof(int));
    printf ("Sa se introduca valorile memorate in vectorul v, numere naturale:\n");
    for(i=0; i<n; i++)
    {
        printf("v[%d]=", i);
        scanf("%d", &v[i]);
    }

    aloc_cit (&m, &w);

    printf("\nVectorul v arata astfel:\n");
    for(i=0; i<n; i++)
        printf("%d   ", v[i]);

    printf("\nVectorul w arata astfel:\n");
    for(i=0; i<m; i++)
        printf("%d   ", w[i]);

    return 0;
}
