#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
    int n, i, max=0, ok=0, nch=0, ncv=0;
    char p[20][100], q[100], a[100], cuv[20], *aux;

    FILE* f;
    if((f=fopen("C:\\Users\\Outsider\\Desktop\\ex2.txt", "w+t"))==NULL)
    {
        puts("\nFisierul nu poate fi deschis!\n");
        exit(1);
    }

    printf("Introduceti numarul de propozitii: ");
    scanf("%d", &n);
    printf("\nIntroduceti %d propozitii:\n", n);
    getchar();
    for(i=1; i<=n; i++)
    {
        gets (p[i]);
        fputs(p[i],f);
        fputs("\n",f);
    }

    /*a) Afişaţi conţinutul fişierului pe ecran;*/

    printf("\n\nSe va citi si scrie pe ecran continutul fisireului:\n");
    fseek(f, 0L, 0);
    strcpy(a, "");
    fgets(a,100,f);
    while(!feof(f))
    {
        puts(a);
        fgets(a,100,f);
    }

    /*b) Introduceţi un cuvânt de la tastatură. Căutaţi cuvântul în fişier şi afişaţi numerele liniilor din fişier care conţin cuvântul respectiv;*/
    printf("\n\nIntroduceti un cuvant pe care sa il cautati in fisier: ");
    scanf("%s", cuv);
    printf("\nLiniile pe care se afla cuvantul sunt: ");
    fseek(f, 0L, 0);
    strcpy(a, "");
    for (i=1; i<=n; i++)
    {
        fgets(a,100,f);
        strcpy(q,a);
        aux=strtok(q, " \n");
        while(aux && strcmp(aux, cuv)!=0)
            aux=strtok(NULL, " \n");
        if(aux)
        {
            ok=1;
            printf("%d; ", i);
        }
    }
    if(!ok)
        printf("niciuna");
    printf("\n");

    /*c) Calculaţi numărul de cuvinte şi numărul de caractere din fişier;*/
    fseek(f, 0L, 0);
    strcpy(a, "");
    for (i=1; i<=n; i++)
    {
        fgets(a,100,f);
        nch+=strlen(a);
        strcpy(q,a);
        aux=strtok(q, " \n");
        while(aux)
        {
            ncv++;
            aux=strtok(NULL, " \n");
        }
    }
    printf("\n\nNumarul de cuvinte din fisier este %d si numarul de caractere din fisier este %d.\n", ncv, nch);

    /*d) Afişaţi linia (liniile) de lungime maximă.*/
    printf("\n\nLinia (liniile) de lungime maxima sunt:\n");
    fseek(f, 0L, 0);
    strcpy(a, "");
    fgets(a,100,f);
    while(!feof(f))
    {
        if(strlen(a)>max)
            max=strlen(a);
        fgets(a,100,f);
    }

    fseek(f, 0L, 0);
    strcpy(a, "");
    fgets(a,100,f);
    while(!feof(f))
    {
        if(strlen(a)==max)
            puts(a);
        fgets(a,100,f);
    }


    fclose(f);

    return 0;
}
