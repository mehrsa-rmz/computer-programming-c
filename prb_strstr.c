#include <stdio.h>
#include <string.h>

int main ()
{
    char a[21], b[21], *p;
    int ok=0;

    printf("Introduceti un cuvant:\n");
    gets (a);

    printf("\nIntroduceti inca un cuvant:\n");
    gets (b);

    if(strstr(a, b))
    {
        ok=1;
        p=strstr(a, b);
        p++;
        if(strstr(p, b))ok=0;
        if(ok) printf ("\nAl doilea cuvant apare o singura data in primul.");
        else printf("\nAl doilea cuvant nu apare doar o data in primul.");
    }
    else printf("\nAl doilea cuvant nu apare deloc in primul.");



    return 0;
}
