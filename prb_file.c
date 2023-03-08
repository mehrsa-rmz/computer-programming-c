#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
    int i, k=0, ok=0;
    char p[100], q[100], *x, c, a[100], cuv1[20], cuv2[20];

    printf("Introduceti o propozitie:\n");
    gets (p);

    FILE* f;
    if((f=fopen("C:\\Users\\Outsider\\Desktop\\ex1.txt", "w+t"))==NULL)
    {
        puts("\nFisierul nu poate fi deschis!\n");
        exit(1);
    }

    fputs("Scrierea sirului in fisierul text cu totul:\n",f);
    fputs(p,f);

    fputs("\n\nScrierea sirului in fisierul text caracter cu caracter:\n",f);
    for(i=0; i<strlen(p); i++)
    {
        fputc(p[i],f);
    }

    fputs("\n\nScrierea sirului in fisierul text cuvant cu cuvant pe o linie:\n",f);
    strcpy(q, p);
    x=strtok(q, " ");
    while (x)
    {
        fputs(x,f);
        fputc(' ',f);
        x=strtok(NULL, " ");
    }

    fputs("\n\nScrierea sirului in fisierul text cuvant cu cuvant pe cate o linie:\n",f);
    strcpy(q, p);
    x=strtok(q, " ");
    while (x)
    {
        fputs(x,f);
        fputs("\n",f);
        x=strtok(NULL, " ");
    }

    printf("\n\nSe va citi si scrie pe ecran continutul fisireului:\nCaracter cu caracter:\n");
    fseek(f, 0L, 0);
    while(!feof(f))
    {
        c=fgetc(f);
        putchar(c);
    }

    printf("\n\nCuvant cu cuvant:\n");
    fseek(f, 0L, 0);
    while(!feof(f))
    {
        fscanf(f, "%s", a);
        printf("%s ", a);
    }

    printf("\n\nIntreaga linie:\n");
    fseek(f, 0L, 0);
    strcpy(a, "");
    fgets(a,100,f);
    while(!feof(f))
    {
        puts(a);
        fgets(a,100,f);
    }

    FILE* af;
    if((af=fopen("C:\\Users\\Outsider\\Desktop\\aux_ex1.txt", "w+t"))==NULL)
    {
        puts("\nFisierul nu poate fi deschis!\n");
        exit(1);
    }
    printf("\n\nIntroduceti un cuvant pe care vreti sa il inlocuiti din fisier:");
    gets(cuv1);
    printf("\n\nIntroduceti un cuvant care vreti sa il inlociasca in fisier:");
    gets(cuv2);

    fseek(f, 0L, 0);
    fgets(a,100,f);
    while(!feof(f))
    {
        x=strtok(a, "\n ");
        while(x!=NULL)
        {if (strcmp(x, cuv1)==0)
            {
                fputs(cuv2,af);
                ok=1;
            }
        else fputs(x,af);
        fputc(' ',af);
        x=strtok(NULL, "\n ");
        }
        fputc('\n',af);
        fgets(a,100,f);
    }
    if(ok)
    {
        fseek(f, 0L, 0);
        fseek(af, 0L, 0);
        fgets(a,100,af);
        while(feof(af)==0)
        {
            fputs(a,f);
            fgets(a,100,af);
        }
    }
    else printf("\nNu se regaseste cuvantul \"%s\" in fisier.", cuv1);

    fclose(f);
    fclose(af);

    return 0;
}
