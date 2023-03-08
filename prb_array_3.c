#include<stdio.h>

int main ()
{
    int n, v[100], w[100], i, j, k=1, ap=1, nr_max_ap=1, c;
    printf("Sa se introduca un nurmar natural pentru n:");
    scanf("%d", &n);
    printf("Sa se introduca valorile memorate in vector, numere intregi:\n");
    for(j=0; j<n; j++)
    {
        printf("v[%d]=", j);
        scanf("%d", &v[j]);
    }

    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
            if (v[i]>v[j])
                {c=v[i]; v[i]=v[j]; v[j]=c;}

    w[0]=v[0];

    for(i=1; i<n; i++)
        if (v[i]==v[i-1])
        {
            ap++;
            if (ap==nr_max_ap)
                w[k++]=v[i];
            else if (ap>nr_max_ap)
            {
                k=0;
                w[k]=v[i];
            }
        }
        else
        {
            ap=1;
            if(nr_max_ap==1)
                w[k++]=v[i];
        }

    printf("\nValorile care au cel mai mare numar de aparitii sunt:\n");
    for (j=0; j<k; j++)
        printf("%d  ", w[j]);

    return 0;
}
