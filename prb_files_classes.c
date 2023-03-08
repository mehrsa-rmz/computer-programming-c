//Ramezani Mehrsa
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct
{
    char nume[20], nr_inm [15];
    int zi, luna, an;
} autot;

typedef struct
{
    int nr_auto, ok;
    autot a[20];
} masini;

masini f1 (int an, char j[3], autot *a, int n)
{
    masini m;
    int i, k;
    m.nr_auto=m.ok=0;

    for(i=0; i<n; i++)
        if(a[i].an==an && strncmp(j, a[i].nr_inm, strlen(j))==0)
        {
            m.a[m.nr_auto]=a[i];
            for(k=0; k<m.nr_auto-1; k++)
                if(strcmp(a[k].nume, a[i].nume)==0)
                    m.ok=1;
            m.nr_auto++;
        }
    return m;
}

void f2(masini m)
{
    FILE *f;
    int i, j, ok=0;
    autot aux;

    if ((f=fopen("lista.txt", "wt"))==NULL)
    {
        puts("Fisierul nu poate fi deschis!\n");
        exit (1);
    }
    for(i=0; i<m.nr_auto; i++)
        for(j=i+1; j<m.nr_auto; j++)
            if ((m.a[i].luna>m.a[j].luna)||(m.a[i].luna==m.a[j].luna && m.a[i].zi>m.a[j].zi))
            {
                aux=m.a[i];
                m.a[i]=m.a[j];
                m.a[j]=aux;
                ok=1;
            }
    for(i=0; i<m.nr_auto; i++)
        fprintf(f, "%s  %d %d %d\n", m.a[i].nr_inm, m.a[i].zi, m.a[i].luna, m.a[i].an);
    fclose(f);
}

int main ()
{
    FILE *f, *g;
    int n=0, an, luna, zi1, luna1=0, an1, i;
    char j[3], nr_inm[15];
    autot a[30];
    masini m;

    if ((f=fopen("autoturisme.bin", "rb"))==NULL)
    {
        puts("Fisierul nu poate fi deschis!\n");
        exit (1);
    }

    fseek(f, 0L, 0);
    while(!feof(f))
    {
        fgets(a[n].nume, 21, f);
        fflush(stdin);
        fscanf(f, "%s %d %d %d", a[n].nr_inm, &a[n].zi, &a[n].luna, &a[n].an);
        n++;
        fflush(stdin);
    }

    printf("Introduceti un an: ");
    scanf("%d", &an);
    printf("Introduceti o prescurtare de judet: ");
    fflush(stdin);
    scanf("%s", j);
    m=f1(an, j, a, n);
    if(m.ok)
        fprintf("\nExista macar un proprietar ce detine doua sau mai multe vehicule prevazute pentru revizie in anul %d si judetul %s.\n\n", an, j);
    else
        fprintf("\nNu exista niciun proprietar ce detine doua sau mai multe vehicule prevazute pentru revizie in anul %d si judetul %s.\n\n", an, j);

    f2(m);

    printf("\nIntroduceti o luna(ca numar): ");
    scanf("%d", &luna);
    if ((g=fopen("lista.txt", "rt"))==NULL)
    {
        puts("Fisierul nu poate fi deschis!\n");
        exit (1);
    }
    fseek(g, 0L, 0);
    for(i=0; i<m.nr_auto && luna1<=luna; i++)
        {
            fflush(stdin);
            fscanf(g, "%s  %d %d %d", nr_inm, &zi1, &luna1, &an1);
            if(luna1==luna)
                printf("%s  %d %d %d\n", nr_inm, zi1, luna1, an1);
        }

    fclose(f);
    fclose(g);

    return 0;
}
