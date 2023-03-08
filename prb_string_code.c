#include <stdio.h>
#include <string.h>

int main ()
{
    char s[100];
    int i;

    printf("Introduceti un text format din litere mici si spatii:\n");
    gets (s);

    for (i=0; i<strlen(s); i++)
        {
            if('a'<=s[i] && s[i]<'z') s[i]++;
            else if (s[i]=='z') s[i]='a';
        }
    printf("\nDupa codificarea sa, textul arata astfel:\n");
    printf("%s", s);

    return 0;
}
