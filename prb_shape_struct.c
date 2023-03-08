#include <stdio.h>

    struct fig_geom
        {
            char nume;
            int raza, lungime, latime;
        };

int main ()
{
    struct fig_geom fig;
    float p, a;
    printf("Alegeti tipul unei figuri geometrice introducand litera c pentru cerc, p pentru patrat, d pentru dreptunghi:");
    scanf("%c", &fig.nume);

    if(fig.nume=='c')
    {
        printf("\nIntroduceti lungimea razei cercului:");
        scanf("%d", &fig.raza);
        p=2*3.14*fig.raza;
        a=3.14*fig.raza*fig.raza;
        printf("\nCercul are circumferinta %.3f si aria %.3f.", p, a);
    }

    if(fig.nume=='p')
    {
        printf("\nIntroduceti lungimea laturii patratului:");
        scanf("%d", &fig.lungime);
        fig.latime=fig.lungime;
        p=4*fig.lungime;
        a=fig.lungime*fig.lungime;
        printf("\nPatratul are perimetrul %.0f si aria %.0f.", p, a);
    }


    if(fig.nume=='d')
    {
        printf("\nIntroduceti lungimea si latimea dreptunghiului:");
        scanf("%d %d", &fig.lungime, &fig.latime);
        p=2*fig.lungime+2*fig.latime;
        a=fig.lungime*fig.latime;
        printf("\nDreptunghiul are perimetrul %.0f si aria %.0f.", p, a);
    }

    return 0;
}
