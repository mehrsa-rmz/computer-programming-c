#include <stdio.h>
#include <string.h>

int main ()
{
    char a[100], b[100];
    int i;

    printf("Introduceti doua cuvinte :\n");
    scanf("%s %s", a, b);

    if (strlen(a)==strlen(b))
        {
            if (strcmp(a, b)==0)
                printf ("\nSunt identice.");
            else printf ("\nNu nici identice, nici subsir al celuilalt cuvant.");
        }
    else
    {
        if (strlen(a)<strlen(b))
        {
            if (strstr(b+strlen(b)-strlen(a), a))
                printf ("\nAl doilea il contine pe primul.");
            else printf ("\nNu nici identice, nici subsir al celuilalt cuvant.");
        }
        else
        {
            if (strstr(a+strlen(a)-strlen(b), b))
                printf ("\nPrimul il contine pe al doilea.");
            else printf ("\nNu nici identice, nici subsir al celuilalt cuvant.");
        }
    }

    return 0;
}
