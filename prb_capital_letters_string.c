#include <stdio.h>
#include <string.h>

void in_sf_maj (char s[100])
{
    int i;
    char t[100], *p;
    t[0]='\0';
    p=strtok(s, " ");
    while (p)
    {
        p[0]-='a'-'A';
        p[strlen(p)-1]-='a'-'A';
        strcat(t, p);
        strcat(t, " ");
        p=strtok(NULL, " ");
    }
    t[strlen(t)-1]='\0';
    strcpy(s,t);
}

int main ()
{
    char s[100];
    int v1, v2;

    printf("Introduceti un sir de caractere format din litere mici si spatii:\n");
    gets (s);

    in_sf_maj(s);

    printf("\nDupa transformarea primei si ultimei litere din fiecare cuvant in majuscule sirul arata astfel:\n%s", s);

    return 0;
}
