#include <stdio.h>

int lit_mari (char *a, char *b, char *c)
{
    if ('a'<=*a && 'z'>=*a) *a=*a+'A'-'a';
    else return 0;

    if ('a'<=*b && 'z'>=*b) *b=*b+'A'-'a';
    else return 0;

    if ('a'<=*c && 'z'>=*c) *c=*c+'A'-'a';
    else return 0;

    return 1;
}

int main()
{
    char n, m, p;
    int ok;
    printf("Sa se introduca cate un caracter pentru n, m si p:");
    scanf("%c %c %c", &n, &m, &p);

    ok=lit_mari(&n, &m, &p);

    if (ok) printf("\nDupa convertirea in majuscule, se obtin literele %c, %c si %c.", n, m, p);
    else printf("\nNu s-a putut realiza convertirea in majuscule a caracterelor.");

    return 0;
}
