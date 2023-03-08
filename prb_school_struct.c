#include <stdio.h>
#include <string.h>

struct student
{
    char nume[50];
    float nota1, nota2, nota3;
};

int main ()
{
    char nume[50];
    int i, j, mat;
    float max1=0, max2=0, max3=0, medmax=0;
    struct student s[7], aux;
    printf("Introduceti informatii pentru 6 studenti:\n");
    for(i=0; i<6; i++)
    {

        printf ("%d: nume:", i+1);
        gets(s[i].nume);
        printf("cele 3 note: ");
        scanf("%f %f %f", &s[i].nota1, &s[i].nota2, &s[i].nota3);
        if(s[i].nota1>max1)
            max1=s[i].nota1;
        if(s[i].nota2>max2)
            max2=s[i].nota2;
        if(s[i].nota3>max3)
            max3=s[i].nota3;
        if((s[i].nota1+s[i].nota2+s[i].nota3)/3>medmax)
            medmax=(s[i].nota1+s[i].nota2+s[i].nota3)/3;
        getchar();
    }

    printf("\nIntroduceti numele unui student: ");
    gets(nume);
    i=0;
    while(strcmp(nume, s[i].nume)!=0)
        i++;
    printf("Notele studentului sunt %.2f, %.2f si %.2f.", s[i].nota1, s[i].nota2, s[i].nota3);

    printf("\n\nIntroduceti 1, 2 sau 3 pentru a selecta materia:");
    scanf("%d", &mat);
    printf("Elevul/elevii cu cea mai mare nota la materia aceasta este/sunt:\n");
    if(mat==1)
    {
        for(i=0; i<6; i++)
            if (s[i].nota1==max1)
                printf("%s; ", s[i].nume);
    }
    if(mat==2)
    {
        for(i=0; i<6; i++)
            if (s[i].nota2==max2)
                printf("%s; ", s[i].nume);
    }
    if(mat==3)
    {
        for(i=0; i<6; i++)
            if (s[i].nota3==max3)
                printf("%s; ", s[i].nume);
    }

    printf("\n\nElevul/elevii cu cea mai mare medie este/sunt:\n");
    for(i=0; i<6; i++)
        if ((s[i].nota1+s[i].nota2+s[i].nota3)/3==medmax)
            printf("%s; ", s[i].nume);

    for(i=0; i<6; i++)
        for(j=i+1; j<6; j++)
            if(s[i].nota2<s[j].nota2)
            {
                aux=s[i];
                s[i]=s[j];
                s[j]=aux;
            }
    printf("\n\nElevii care nu promoveaza la minim o materie sunt:\n");
    for(i=0; i<6; i++)
        if(s[i].nota1<5 || s[i].nota2<5 || s[i].nota3<5)
            printf("%s; ", s[i].nume);


    return 0;
}
