#include <stdio.h>

int perfect(int nr)
{
    int div=1;

    for (int i=2; i<nr; i++) if(nr%i==0) div+=i;

    if (div==nr) return 1;
    else return 0;
}

int main()
{
    int n, ok;
    printf("Sa se introduca o valoare pentru n, numar natural:");
    scanf("%d", &n);

    ok=perfect(n);
    if (ok) printf("\nNumarul %d este perfect.", n);
    else printf("\nNumarul %d nu este perfect.", n);



    return 0;
}
