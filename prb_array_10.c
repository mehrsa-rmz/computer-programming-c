#include<stdio.h>

int main ()
{
    int n, v[100], m, w[100], k=0, z[200], i, j;
    printf("Sa se introduca un numar natural pentru n:");
    scanf ("%d", &n);
    printf("Sa se introduca valorile memorate in primul vector, numere intregi ordonate crescator:\n");

    for(i=0; i<n; i++)
    {
        printf("v[%d]=", i);
        scanf("%d", &v[i]);
    }

    printf("Sa se introduca un numar natural pentru m:");
    scanf ("%d", &m);
    printf("Sa se introduca valorile memorate in al doilea vector, numere intregi ordonate crescator:\n");

    for(i=0; i<m; i++)
    {
        printf("w[%d]=", i);
        scanf("%d", &w[i]);
    }
    i=j=0;
    while(i<n && j<m)
    {
        while (v[i]%2==0 && i<n) i++;
        while (w[j]%2==0 && j<m) j++;
        if (i==n || j==m) break;
        if(v[i]<w[j])
        {
            z[k++]=v[i];
            i++;
        }
        else
        {
            z[k++]=w[j];
            j++;
        }
    }

    while (i<n)
    {
        if(v[i]%2==0)
        {
            i++;
            continue;
        }
        z[k++]=v[i++];
    }

    while (j<m)
    {
        if(w[j]%2==0)
        {
            j++;
            continue;
        }
        z[k++]=w[j++];
    }

    printf("\nVectorul obtinut prin interclasarea valorilor impare din cei doi vectori dati arata astfel:\n");
    for(i=0; i<k; i++)
        printf("%d   ", z[i]);


    return 0;
}
