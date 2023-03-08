#include <stdio.h>
#include <string.h>

    struct carte
        {
            char titlu[100];
            int an;
            struct autor
            {
                char nume[100], prenume[100], gen;
            } a;
        }c[1000];

    void autor (char num[100], char prenum[100], int n)
    {
        for(int i=0; i<n; i++)
            if(strcmp(c[i].a.nume, num)==0 && strcmp(c[i].a.prenume, prenum)==0)
        {
            printf("\nCartea \"%s\" scrisa de %s %s a fost publicata in anul %d si apartine genului ", c[i].titlu, prenum, num, c[i].an);
            if(c[i].a.gen=='D') printf("dramatic.");
            if(c[i].a.gen=='C') printf("comedie.");
            if(c[i].a.gen=='T') printf("teatru.");
        }
    }

    void autor_max (int n)
    {
        int l, max=0;
        char num[100], prenum[100];
        for (int i=0; i<n; i++)
        {
            l=0;
            for(int j=i+1; j<n; j++)
            if(strcmp(c[i].a.nume, c[j].a.nume)==0 && strcmp(c[i].a.prenume, c[j].a.prenume)==0) l++;
            if(l>max)
            {
                max=l;
                strcpy(num, c[i].a.nume);
                strcpy(prenum, c[i].a.prenume);
            }
        }
        printf("\n\nAutorul cu cel mai mare numar de carti publicate de editura este %s %s", prenum, num);
    }

    void an_gen(int n, int an, char gen)
    {
        for (int i=0; i<n; i++)
            if(c[i].an==an && c[i].a.gen==gen)
                printf ("\"%s\"\n", c[i].titlu);
    }

    void ordonare_titlu (int n)
    {
        struct carte aux;
        for (int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                if(strcmp(c[i].titlu, c[j].titlu)>0)
                {
                    aux=c[i];
                    c[i]=c[j];
                    c[j]=aux;
                }
    }

int main ()
{
    int n, i, an;
    char prenume[100], nume[100], gen;

    printf("Introduceti numarul de carti publicate de editura:");
    scanf("%d", &n);

    printf("\nIntroduceti detaliile fiecarei carti:\n");
    for(i=0; i<n; i++)
    {
        getchar();
        printf ("%d: titlu:", i+1);
        gets(c[i].titlu);
        printf("an:");
        scanf("%d", &c[i].an);
        getchar();
        printf("prenume si nume autor:");
        scanf ("%s %s", c[i].a.prenume, c[i].a.nume);
        getchar();
        printf("Intruduceti D pentru genul dramatic, C pentru comedie sau T pentru teatru:");
        scanf("%c", &c[i].a.gen);
    }

    printf("\n\nIntroduceti prenumele si numele unui autor:");
    scanf ("%s %s", prenume, nume);
    autor(nume, prenume, n);

    autor_max(n);

    printf("\n\nIntroduceti un an si D pentru genul dramatic, C pentru comedie sau T pentru teatru:");
    scanf ("%d %c", &an, &gen);
    an_gen(n, an, gen);

    ordonare_titlu(n);
    printf("\n\nIn ordine lexicografica, cartile sunt:\n");
    for(i=0; i<n; i++)
        printf("\"%s\" ", c[i].titlu);


    return 0;
}
