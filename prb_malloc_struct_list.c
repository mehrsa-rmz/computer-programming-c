#include <stdio.h>
#include <stdlib.h>

struct produs
{
    int id_produs;
    int cant_produs;
    float pret_produs;
    struct produs* urm;
};

typedef struct produs ELEM;

int main ()
{
    ELEM *cap_l, *p, *q;
    int i, n;

    printf("Introduceti numarul de produse:");
    scanf("%d", &n);

    p=(ELEM*)malloc(sizeof(ELEM));
    if(p==NULL)
    {
        printf("\nAlocarea dinamica a esuat.");
        exit(1);
    }
    printf("\nIntroduceti produsele:");
    printf("\n1:\nCodul produsului: ");
    scanf("%d", &p->id_produs);
    printf("Cantitatea produsului: ");
    scanf("%d", &p->cant_produs);
    printf("Pretul produsului: ");
    scanf("%f", &p->pret_produs);
    p->urm=NULL;

    cap_l=p;

    for(i=2; i<=n; i++)
    {
        q=(ELEM*)malloc(sizeof(ELEM));
        if(q==NULL)
        {
            printf("\nAlocarea dinamica a esuat.");
            exit(1);
        }
        printf("\n%d:\nCodul produsului: ", i);
        scanf("%d", &q->id_produs);
        printf("Cantitatea produsului: ");
        scanf("%d", &q->cant_produs);
        printf("Pretul produsului: ");
        scanf("%f", &q->pret_produs);
        q->urm=NULL;
        p->urm=q;
        p=q;
    }

    for(p=cap_l; p!=NULL; p=q)
    {
        q=p->urm;
        free(p);
    }

    return 0;
}
