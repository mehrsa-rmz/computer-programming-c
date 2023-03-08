#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct persoana
{
    char num[30];
    int v;
    struct persoana* urm;
};

typedef struct persoana PERS;

int main ()
{
    PERS *cap_l, *p, *q;
    int i, n;
    printf("Introduceti numarul de persoane:");
    scanf("%d", &n);
    p=(PERS*)malloc(sizeof(PERS));
    if(p==NULL)
    {
        printf("\nAlocarea dinamica a esuat.");
        exit(1);
    }
    printf("\n1:\nNume:");
    getchar();
    gets(p->num);
    printf("Varsta:");
    scanf("%d", &p->v);
    p->urm=NULL;

    cap_l=p;

    for(i=2; i<=n; i++)
    {
        q=(PERS*)malloc(sizeof(PERS));
        if(q==NULL)
        {
            printf("\nAlocarea dinamica a esuat.");
            exit(1);
        }
        printf("\n%d:\nNume:", i);
        getchar();
        gets(q->num);
        printf("Varsta:");
        scanf("%d", &q->v);
        q->urm=NULL;
        p->urm=q;
        p=q;
    }

    p=cap_l;
    while(p!=NULL && (strcmp(p->num, "George")!=0 || p->v!=19))
        p=p->urm;


    if (p!=NULL)
    {
        if(p->urm!=NULL)
        {
            if(p->urm->v<19)
                printf("\nPersoana de dupa George, %s, este mai tanara.", p->urm->num);
            else
                printf("\nPersoana de dupa George, %s, nu este mai tanara.", p->urm->num);
        }
        else
            printf("\nNu exista nimeni dupa George.");
    }
    else
        printf("\nNu exista vreun George de 19 ani.");

    for(p=cap_l; p!=NULL; p=q)
    {
        q=p->urm;
        free(p);
    }

    return 0;
}
