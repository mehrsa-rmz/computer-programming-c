#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
    int *v, n, i, nr;
    char p[20][100], q[100], a[100], cuv[20], *aux;

    FILE* f;
    if((f=fopen("C:\\Users\\Outsider\\Desktop\\ex3a.txt", "w+t"))==NULL)
    {
        puts("\nFisierul nu poate fi deschis!\n");
        exit(1);
    }

    FILE* g;
    if((g=fopen("C:\\Users\\Outsider\\Desktop\\ex3b.txt", "w+b"))==NULL)
    {
        puts("\nFisierul nu poate fi deschis!\n");
        exit(1);
    }

    printf("Introduceti numarul de elemente din vector: ");
    scanf("%d", &n);
    v = (int)malloc (n * sizeof(int));
    if(v==NULL)
    {
        printf("\nAlocarea dinamica a esuat.");
        exit(1);
    }

    printf("\nIntroduceti elementele:\n");
    for(i=0; i<n; i++)
        {
            printf("v[%d]=", i);
            scanf("%d", &v[i]);
            fprintf(f, "%d ", v[i]);
            fprintf(g, "%d ", v[i]);
        }

    printf("\n\nSe va citi si scrie pe ecran continutul:\nfisireului text:\n");
    fseek(f, 0L, 0);
    while(fscanf(f, "%d", nr))
        printf("%d ", nr);

    printf("\n\n fisireului binar:\n");
    fseek(f, 0L, 0);
    while(fscanf(f, "%d", nr))
        printf("%d ", nr);

    fclose(f);
    fclose(g);

    return 0;
}

