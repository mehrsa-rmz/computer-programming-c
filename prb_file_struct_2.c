#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct
{
    char nume[20];
    int cant;
} lista;

typedef struct
{
    char firma[30];
    int nr_buc;
    float pret;
} produs;

typedef struct
{
    char nume[30];
    int nr_tipuri;
    produs p[20];
} magazin;

void ordonare(produs* v, int n)
{
    int i, j;
    produs aux;
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
            if(v[i].nr_buc>v[j].nr_buc)
        {
            aux=v[i];
            v[i]=v[j];
            v[j]=aux;
        }
}

produs cautare(FILE *f, char d[], int c, magazin *v, int *nr)
{
    int i, j, poz;
    float min;

    produs zero;
    zero.firma[0]='\0';
    zero.nr_buc=0;
    zero.pret=0;

    *nr=0;
    fseek(f,0L,0);
    while(!feof(f))
    {
        fgets(v[*nr].nume,21,f);
        v[*nr].nume[strlen(v[*nr].nume)-1]='\0';
        if(feof(f))
        {
            (*nr)=0;
            break;
        }
        fscanf(f,"%d",&v[*nr].nr_tipuri);
        fgetc(f);
        fread(v[*nr].p, sizeof(produs), v[*nr].nr_tipuri, f);
        ordonare(v[*nr].p, v[*nr].nr_tipuri);
        (*nr)++;
    }

    i=0;
    while(strcmp(d, v[i].nume)!=0 && i<(*nr)) i++;
    if(i<(*nr))
    {
        j=0;
        while(v[i].p[j].nr_buc<c && j<v[i].nr_tipuri) j++;
        if(j<v[i].nr_tipuri)
        {
            poz=j;
            min=v[i].p[j].pret;
            j++;
            while(j<v[i].nr_tipuri)
                {
                    if(min>v[i].p[j].pret)
                    {
                        min=v[i].p[j].pret;
                        poz=j;
                    }
                    j++;
                }
            return v[i].p[j];
        }
        else return zero;
    }
    else return zero;
}

int main ()
{
    FILE *l, *m, *b;
    lista x[20];
    magazin y[20];
    produs prod;
    int nx=0, ny=0, i;
    float s=0;

    if((l=fopen("lista.txt", "rt"))==NULL)
    {
        puts("Fisierul nu poate fi deschis!\n");
        exit (1);
    }
    while(!feof(l))
    {
        fscanf(l, "%s", x[nx].nume);
        if(feof(l))
        {
            nx=0;
            break;
        }
        fscanf(l,"%d",&x[nx].cant);
        fgetc(l);
        nx++;
    }

    if((m=fopen("magazin.bin", "rb"))==NULL)
    {
        puts("Fisierul nu poate fi deschis!\n");
        exit (1);
    }

    if((b=fopen("bon.bin", "wb"))==NULL)
    {
        puts("Fisierul nu poate fi deschis!\n");
        exit (1);
    }

    fprintf(b, "BON\n\n");
    for(i=0; i<nx; i++)
    {
        prod=cautare(m, x[i].nume, x[i].cant, y, &ny);
        if(prod.firma[0]=='\0')
            fprintf(b, "Nu au %s.\n", x[i].nume);
        else
            {
                fprintf("-%s, cantitate %d, cost %.2f\n", x[i].nume, x[i].cant, (x[i].cant)*(prod.pret));
                s+=(x[i].cant)*(prod.pret);
            }
    }
    fprintf(b, "\nCOST FINAL: %.2f", s);


    fclose(l);
    fclose(m);
    fclose(b);

    return 0;
}
