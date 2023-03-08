#include <stdio.h>
#include <string.h>

int main ()
{
    char s[100], t[100], cuv[100], *p;
    int i, in=0, sf=-1, nr=0;

    printf("Introduceti un sir de caractere:\n");
    gets (s);

    strcpy(t, s);
    p=strtok(t, " ");
    while (p)
    {
        nr++;
        p=strtok(NULL, " ");
    }

    printf("\nSirul are %d cuvinte.\n\n", nr);

    for(i=0; i<strlen(s); i++)
    {
        if (s[i+1]==' ' || s[i+1]=='\0')
            sf= i;
        if(in<=sf)
        {
            strncpy(cuv, s+in, sf-in+1);
            cuv[sf-in+1]='\0';
            i++;
            while(s[i]==' ' && i<strlen(s))
                i++;
            in=i;
            i--;
        }
    }

    return 0;
}
