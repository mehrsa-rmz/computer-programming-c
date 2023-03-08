#include <stdio.h>
#include <stdlib.h>

struct elemente
{
    int v;
    struct elem* urm;
};

typedef struct elemente ELEM;

int main ()
{
    ELEM *cap_l, *p, *q;
    int i, n, ok;
    printf("Introduceti numarul de elemente:");
    scanf("%d", &n);
    p=(ELEM*)malloc(sizeof(ELEM));
    if(p==NULL)
    {
        printf("\nAlocarea dinamica a esuat.");
        exit(1);
    }
    printf("\n1:\nValoare:");
    scanf("%d", &p->v);
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
        printf("\n%d:\nValoare:", i);
        scanf("%d", &q->v);
        q->urm=NULL;
        p->urm=q;
        p=q;
    }

    printf ("\nElementele sunt:\n");
    p=cap_l;
    while(p!=NULL)
    {
        printf("%d; ", p->v);
        p=p->urm;
    }

    printf ("\n\nDupa eliminarea valorilor pare, elementele sunt:\n");
    p=cap_l;
    ok=1;
    while(p!=NULL)
    {
        if(p->v%2)
        {
            printf("%d; ", p->v);
            ok=0;
            p=p->urm;
        }
        else
        {
            if(ok)
            {
                q=p;
                cap_l=p->urm;
                p=p->urm;
                free(q);
            }
            else
            {
                q=p;
                p=p->urm;
                free(q);
            }

        }

    }

    for(p=cap_l; p!=NULL; p=q)
    {
        q=p->urm;
        free(p);
    }

    return 0;
}

