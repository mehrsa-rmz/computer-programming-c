#include <stdio.h>
#include <string.h>

int main ()
{
    char s[100];
    int i, cuv=0;

    printf("Introduceti un text format din litere mici si spatii:\n");
    gets (s);

    for (i=0; i<strlen(s); i++)
        if((i==0 || s[i-1]==' ') && strchr("aeiou", s[i])) cuv++;

    printf("\nExista %d cuvinte care incep cu o vocala.", cuv);


    return 0;
}
