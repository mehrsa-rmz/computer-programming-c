#include<stdio.h>

int main ()
{
    int n, v[100], l, lmax, in, sf, inm, sfm;
    printf("Sa se introduca un numar natural pentru n:");
    scanf ("%d", &n);
    printf("Sa se introduca valorile memorate in vector, numere intregi:\n");

    for(int i=0; i<n; i++)
    {
        printf("v[%d]=", i);
        scanf("%d", &v[i]);
        if(i==0)
        {
            l=lmax=1;
            inm=sfm=in=sf=0;
        }
        else
        {
            if(v[i]>=v[i-1])
            {
                sf++;
                l++;
                if(l>lmax)
                {
                    lmax=l;
                    inm=in;
                    sfm=sf;
                }
            }
            else
            {
                in=sf=i;
                l=1;
            }
        }
    }

    printf("\nCea mai lunga secventa de numere consecutive ordonate crescator din vector este:\n");
    for(int i=inm; i<=sfm; i++)
        printf("%d   ", v[i]);

    return 0;
}
