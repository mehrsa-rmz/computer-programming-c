#include <stdio.h>

char numere (int a, int b, int c)
{
    if(a==b && a==c) return 'I';
    if(a<=b && b<=c) return 'C';
    if(a>=b && b>=c) return 'D';
    return 'N';
}

int main()
{
    int n, m, p;
    char ok;
    printf("Sa se introduca cate o valoare pentru n, m si p, numere intregi:");
    scanf("%d %d %d", &n, &m, &p);

    ok=numere(n, m, p);

    if (ok=='I') printf("\nNumerele %d, %d si %d sunt identice.", n, m, p);
    if (ok=='C') printf("\nNumerele %d, %d si %d sunt ordonate crescator.", n, m, p);
    if (ok=='D') printf("\nNumerele %d, %d si %d sunt ordonate descrescator.", n, m, p);
    if (ok=='N') printf("\nNumerele %d, %d si %d sunt neordonate.", n, m, p);

    return 0;
}
