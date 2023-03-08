//312AB, Ramezani Mehrsa
#include <stdio.h>
#include <stdlib.h>

void vector (float **v, int *n)
{
    int i;
    printf("Sa se introduca numarul de studenti:");
    scanf("%d", n);
    *v=(float*) calloc(*n, sizeof(float));
    printf("\n\nSa se introduca mediile studentilor:\n");
    for(i=0; i<*n; i++)
    {
        printf("v[%d]=", i);
        scanf("%f", &(*v)[i]);
    }
}

void modificare (float **v, int *n)
{
    *n=*n+2;
    *v=(float*)realloc(*v, *n*sizeof(float));
    printf("\n\nSa se adauge medii pentru inca doi studenti:\n");
    scanf("%f %f", &(*v)[*n-2], &(*v)[*n-1]);
}

int main ()
{
    int n, i, nr=0;
    float *v;

    vector(&v, &n);
    modificare(&v, &n);

    for(i=0; i<n; i++)
        if(v[i]>9.5)
            nr++;

    printf("\n\nExista %d studenti care au media mai mare de 9.50.", nr);
    free(v);
    return 0;
}
