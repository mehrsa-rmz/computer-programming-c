#include <stdio.h>
#include <string.h>

void voc_maj (char s[100])
{
    int i;
    for (i=0; i<strlen(s); i++)
    {
        if (strchr("aeiou", s[i]))
            s[i]=s[i]-('a'-'A');
    }
}

int main ()
{
    char s[100];
    int v1, v2;

    printf("Introduceti un cuvant format din litere mici:\n");
    gets (s);

    voc_maj(s);

    printf("\nDupa transformarea vocalelor in majuscule cuvantul arata astfel:\n%s", s);

    return 0;
}
