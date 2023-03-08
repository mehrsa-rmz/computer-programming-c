#include <stdio.h>

void vector (int **w, int *m)
{
    int i;
    printf ("\nSa se introduca un numar natural, care reprezinta numarul de elemente dintr-un vector:");
    scanf("%d", m);

    *w=(int *) calloc (*m, sizeof(int));

    printf ("Sa se introduca valorile memorate in vector, numere intregi:\n");
    for(i=0; i<*m; i++)
    {
        printf("pe pozitia %d:", i);
        scanf("%d", &(*w)[i]);
    }
}

void afisare_v (int *v, int n)
{
    for (int i=0; i<n; i++)
        printf("%d   ", v[i]);
    printf("\n");
}

int * combinare (int *v, int *w, int *m, int n)
{
    int k=0;
    v=(int*)realloc(v, (*m+n)*sizeof(int));
    for(int i=*m; i<*m+n; i++)
        v[i]=w[k++];
    *m=*m+n;
    return v;
}

int main ()
{
    int *v, m, *w, n, i, j;
    vector (&v, &m);
    vector (&w, &n);

    printf("\nDupa combinarea celor doi vectori se obtine urmatorul vector:\n");

    if(n<m)
    {
        v=combinare(v,w,&m,n);
        afisare_v(v,m);
    }
    else
    {
        w=combinare(w,v,&n,m);
        afisare_v(w,n);
    }

    return 0;
}



