#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct numere
{
    int nr;
    struct numere* urm;
};

typedef struct numere ELEM;

int main ()
{
    ELEM *cap_l, *p, *q;
    int i, n, el;

    printf("Introduceti numarul de elemente:");
    scanf("%d", &n);

    p=(ELEM*)malloc(sizeof(ELEM));
    if(p==NULL)
    {
        printf("\nAlocarea dinamica a esuat.");
        exit(1);
    }
    printf("\nIntroduceti numerele (se va sterge prima aparitie a lui 6):");
    printf("\n1: ");
    scanf("%d", &p->nr);
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
        printf("\n%d: ", i);
        scanf("%d", &q->nr);
        q->urm=NULL;
        p->urm=q;
        p=q;
    }

    if (cap_l->nr==6)
    {
        q=cap_l;
        cap_l=cap_l->urm;
        free(q);
        printf ("\nPrimul element continea valoarea 6, asadar a fost sters.\n");
    }
    else
    {
        p=cap_l->urm;
        el=2;
        while(p!=NULL && p->nr!=6)
        {
            el++;
            p=p->urm;
        }
        if(p==NULL) printf("\nNu exista elemente cu valoarea 6.\n");
        else printf("\nElementul %d are valoarea 6.\n", el);
    }

    q=(ELEM*)malloc(sizeof(ELEM));
    if(q==NULL)
    {
        printf("\nAlocarea dinamica a esuat.");
        exit(1);
    }
    printf("\nElementul de inserat pe pozitia trei este: ");
    scanf("%d", &q->nr);
    q->urm=cap_l->urm->urm;
    cap_l->urm->urm=q;


    printf ("\nDupa inserare se obtine urmatoarea ordine:\n");
    p=cap_l;
    while(p!=NULL)
    {
        printf("%d   ", p->nr);
        p=p->urm;
    }


    for(p=cap_l; p!=NULL; p=q)
    {
        q=p->urm;
        free(p);
    }

    return 0;
}


