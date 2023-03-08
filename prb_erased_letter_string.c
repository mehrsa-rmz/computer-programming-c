#include <stdio.h>
#include <string.h>

int main ()
{
    char s[100], t[100];
    int i;

    printf("Introduceti cuvantul:\n");
    gets (s);

    printf("\nToate variantele de a scrie cuvantul fara una dintre litere sunt:\n");
    for (i=0; i<strlen(s); i++)
        {
            strncpy(t, s, i);
            t[i]='\0';
            strcat(t, s+i+1);
            printf("%s \n", t);
        }


    return 0;
}
