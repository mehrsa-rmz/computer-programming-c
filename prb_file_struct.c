#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct
{
    char nume[30];
    float debit, credit;
    int cod;
} CLIENT;

int cod_max (CLIENT v[], int n)
{
    int i, max=0;
    for(i=0; i<n; i++)
        if(max<v[i].cod)
            max=v[i].cod;
    return max;
}

void grupare (CLIENT *v1, int n1, CLIENT *v2, int n2, CLIENT *ea, int *na, CLIENT *eb, int *nb, CLIENT *eab, int *nab)
{
    int i, j;
    *na=*nb=*nab=0;

    for(i=0; i<n1; i++)
    {
        j=0;
        while(strcmp(v2[j].nume, v1[i].nume)!=0 && j<n2)
            j++;
        if (j==n2)
            ea[(*na)++]=v1[i];
        else
        {
            eab[*nab]=v1[i];
            eab[*nab].debit=v1[i].debit+v2[j].debit;
            eab[*nab].credit=v1[i].credit+v2[j].credit;
            eab[*nab].cod=v2[j].cod;
            (*nab)++;
        }
    }

    for(i=0; i<n2; i++)
    {
        j=0;
        while(strcmp(v2[i].nume, v1[j].nume)!=0 && j<n1)
            j++;
        if (j==n1)
            eb[(*nb)++]=v2[i];
    }

}

int main ()
{
    FILE *b1, *b2, *f;
    CLIENT v1[20], v2[20], va[20], vb[20], vab[20];
    int n1, n2, na, nb, nab, cmax=0, i;

    if((f=fopen("clientibanca.bin", "wb"))==NULL)
    {
        puts("Fisierul nu poate fi deschis!\n");
        exit (1);
    }

    if((b1=fopen("b1.txt", "rt"))==NULL)
    {
        puts("Fisierul nu poate fi deschis!\n");
        exit (1);
    }
    n1=0;
    fseek(b1,0L,0);
    while(!feof(b1))
    {
        fgets(v1[n1].nume,21,b1);
        v1[n1].nume[strlen(v1[n1].nume)-1]='\0';
        if(feof(b1))
        {
            n1=0;
            break;
        }
        fscanf(b1,"%f%f%d",&v1[n1].debit,&v1[n1].credit,&v1[n1].cod);
        fgetc(b1);
        n1++;
    }
    for(i=0; i<n1; i++)
        printf("%s %.1f %.1f %d \n", v1[i].nume, v1[i].debit, v1[i].credit, v1[i].cod);
    printf("\n");

    if((b2=fopen("b2.txt", "rt"))==NULL)
    {
        puts("Fisierul nu poate fi deschis!\n");
        exit (1);
    }
    n2=0;
    fseek(b2,0L,0);
    while(!feof(b2))
    {
        fgets(v2[n2].nume,21,b2);
        v2[n2].nume[strlen(v2[n2].nume)-1]='\0';
        if(feof(b2))
        {
            n2=0;
            break;
        }
        fscanf(b2,"%f%f%d",&v2[n2].debit,&v2[n2].credit,&v2[n2].cod);
        fgetc(b2);
        n2++;
    }
    for(i=0; i<n2; i++)
        printf("%s %.1f %.1f %d \n", v2[i].nume, v2[i].debit, v2[i].credit, v2[i].cod);
    printf("\n");

    cmax=cod_max(v2, n2);

    grupare(v1, n1, v2, n2, va, &na, vb, &nb, vab, &nab);

    for(i=0; i<na; i++)
        va[i].cod=cmax+i+1;

    for(i=0; i<na; i++)
        printf("%s %.1f %.1f %d \n", va[i].nume, va[i].debit, va[i].credit, va[i].cod);
    printf("\n");
    for(i=0; i<nb; i++)
        printf("%s %.1f %.1f %d \n", vb[i].nume, vb[i].debit, vb[i].credit, vb[i].cod);
    printf("\n");
    for(i=0; i<nab; i++)
        printf("%s %.1f %.1f %d \n", vab[i].nume, vab[i].debit, vab[i].credit, vab[i].cod);
    printf("\n");

    if(nb!=0)
        fwrite(vb, sizeof(CLIENT), nb, f);
    if(nab!=0)
        fwrite(vab, sizeof(CLIENT), nab, f);
    if(na!=0)
        fwrite(va, sizeof(CLIENT), na, f);

    printf("Numarul total de clienti din fisier este: %d", ftell(f)/sizeof(CLIENT));

    fclose(b1);
    fclose(b2);
    fclose(f);
    return 0;
}
