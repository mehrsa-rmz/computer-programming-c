#include<stdio.h>
#include<math.h>

int main ()
{
    int n, v[100], j, nr_min=1;
    float med=0;
    printf("Sa se introduca un nurmar natural pentru n:");
    scanf("%d", &n);
    printf("Sa se introduca valorile memorate in vector, numere intregi:\n");
    for(j=0; j<n; j++)
    {
        printf("v[%d]=", j);
        scanf("%d", &v[j]);
        if (j==0)
            nr_min=v[j];
        else if (v[j]<nr_min)
            nr_min=v[j];
        med+=v[j];
    }
    med/=n;


    printf("\nSubpunctul a):\n");
    j=0;
    while(j<n && fabs((float)v[j]-med)>0.01)
        j++;
    if (j==n)
        printf("Valoarea medie nu apartine vectorului.\n");
    else
        printf("Valoarea medie apartine vectorului.\n");

    printf("\nSubpunctul b):\n");
    printf("Valoarea minima din vector este %d si apare pe pozitia/pozitiile:\n", nr_min);
    for(j=0; j<n; j++)
        if (v[j]==nr_min)
            printf("%d  ", j);



    return 0;
}
