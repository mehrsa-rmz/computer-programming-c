#include <stdio.h>
#include <string.h>

int main ()
{
    char n1[100], n2[100];
    int v1, v2;

    printf("Introduceti numele primei persoane:\n");
    gets (n1);
    printf("Introduceti varsta primei persoane:\n");
    scanf("%d", &v1);
    getchar();

    printf("\nIntroduceti numele celei de a doua persoane:\n");
    gets (n2);
    printf("Introduceti varsta celei de a doua persoane:\n");
    scanf("%d", &v2);

    if (strcmp(n1, n2)==0)
        printf("\nCele doua persoane se numesc amandoua %s si au varstele %d si %d\n", n1, v1, v2);
    else
    {
        if (v1==v2)
            printf("\nCele doua persoane au aceasi varsta, %d, si se numesc\n%s si\n%s.\n", v1, n1, n2);
        else
            printf("\nPersoana mai tanara este %s.", v1<v2 ? n1:n2);
    }

    return 0;
}
