#include <stdio.h>

int cf_pare(int nr, int *rez)
{
    int cop=nr, p=1;
    *rez=0;

    while (cop>0)
    {
        if(cop%2==0)
        {*rez=*rez+p*(cop%10); p*=10;}
        cop/=10;
    }

    if (*rez) return 1;
    else return 0;
}

int main()
{
    int n, ok, r;
    printf("Sa se introduca o valoare pentru n, numar natural nenul:");
    scanf("%d", &n);

    ok=cf_pare(n, &r);
    if (ok) printf("\nNumarul format doar din cifre pare obtinut din %d este %d.", n, r);
    else printf("\nNu s-a putut obtine un numar format doar din cifre pare pentru %d.", n);



    return 0;
}
