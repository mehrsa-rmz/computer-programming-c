#include <stdio.h>
#include <string.h>

int main ()
{
    char s1[100], s2[100], s3[100], t[300];
    int i, x;

    printf("Introduceti primul sir:\n");
    gets (s1);

    printf("\nIntroduceti al doilea sir:\n");
    gets (s2);

    printf("\nIntroduceti al treilea sir:\n");
    gets (s3);

    strcpy(t, s1);
    for (i=0; i<=strlen(s2); i++)
        t[strlen(s1)+i]=s2[i];
    x=strlen(t);
    for (i=0; i<=strlen(s3); i++)
        t[x+i]=s3[i];

    printf("\nCele trei siruri concatenate arata astfel:\n");
    printf("%s", t);

    return 0;
}
