#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cuvinte
{
    char cuv[15];
    struct cuvinte* urm;
};

typedef struct cuvinte ELEM;

int main ()
{
    ELEM *cap_l, *p, *q;
    int i, n;
    char t[200];
    t[0]='\0';

    printf("Introduceti numarul de cuvinte:");
    scanf("%d", &n);

    p=(ELEM*)malloc(sizeof(ELEM));
    if(p==NULL)
    {
        printf("\nAlocarea dinamica a esuat.");
        exit(1);
    }
    printf("\nIntroduceti cuvintele:");
    printf("\n1: ");
    scanf("%s", p->cuv);
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
        scanf("%s", q->cuv);
        q->urm=NULL;
        p->urm=q;
        p=q;
    }

    printf ("\nCuvintele si adresele sunt:\n");
    p=cap_l;
    while(p!=NULL)
    {
        printf("\'%s\' la %p; \n", p->cuv, p->cuv);
        p=p->urm;
    }

    printf ("\nDupa concatenarea cuvintelor se obtine fraza:\n");
    p=cap_l;
    while(p!=NULL)
    {
        strcat(t, p->cuv);
        strcat(t, " ");
        p=p->urm;
    }
    printf("%s", t);

    for(p=cap_l; p!=NULL; p=q)
    {
        q=p->urm;
        free(p);
    }

    return 0;
}

