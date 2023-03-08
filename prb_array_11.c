#include<stdio.h>

int main ()
{
    int n, v[100], i, j, c, min, max, pozmin=0, pozmax=0;
    printf("Sa se introduca un numar natural pentru n:");
    scanf ("%d", &n);
    printf("Sa se introduca valorile memorate in vector, numere intregi:\n");

    for(i=0; i<n; i++)
       {
       printf("v[%d]=", i);
       scanf("%d", &v[i]);
       if(i==0)min=max=v[0];
       else
       {
           if(v[i]<min){min=v[i]; pozmin=i;}
           if(v[i]>max){max=v[i]; pozmax=i;}
       }
       }

    if (pozmin<pozmax)
    {
        c=pozmin; pozmin=pozmax; pozmax=c;
    }

    if(pozmin-pozmax==1) printf("\nNu se poate ordona.\n");
    else
    {
        for(i=pozmax+1; i<pozmin; i++)
        for(j=i+1; j<pozmin; j++)
        if(v[i]>v[j])
        {
            c=v[i]; v[i]=v[j]; v[j]=c;
        }

    printf("\nDupa ordonarea crescatoare a elementelor aflate intre elementul minim si cel maxim, vectorul arata astfel:\n");
    for(i=0; i<n; i++) printf("%d   ", v[i]);
    }

    return 0;
}

