#include <stdio.h>

int palindrom(int nr)
{
    int cop=nr, x=0;
    while (cop>0)
    {
        x=x*10+cop%10;
        cop/=10;
    }
    if (x==nr) return 1;
    else return 0;
}

int main()
{
    int n, ok;
    printf("Sa se introduca o valoare pentru n, numar natural:");
    scanf("%d", &n);

    ok=palindrom(n);
    if (ok) printf("\n%d este palindrom.", n);
    else printf("\n%d nu este palindrom.", n);



    return 0;
}
