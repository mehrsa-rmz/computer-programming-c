#include<stdio.h>

int main ()
{
    int x=0, i, j, k=1, iok=1, dok=1;
    float v[100], c;
    printf("Sa se introduca valorile memorate in vector, numere reale, cu spatiu intre ele si sa se incheie sirul de valori cu o paranteza dreapta:\n");
    while (scanf("%f", &v[x])) x++;

    for(i=0; i<x; i++)
        for(j=i+1; j<x; j++)
            if (v[i]>v[j])
                {c=v[i]; v[i]=v[j]; v[j]=c;}
    for(i=0; i<x-1; i++)
        if(v[i]==v[i+1])dok=0;
        else iok=0;
    if (iok) printf ("Valorile vectorului sunt toate identice.");
    else if (dok) printf ("Valorile vectorului sunt toate distincte.");
    else printf ("Valorile vectorului sunt oarecare.");
    return 0;
}
