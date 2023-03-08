#include <stdio.h>

    struct timp {int ora, minut, secunda;} m1, m2;

int main ()
{
    struct timp m3;
    printf("Introduceti doua momente din zi sub forma hh mm ss:");

    printf("\nm1-> ");
    scanf("%d %d %d", &m1.ora, &m1.minut, &m1.secunda);

    printf("\nm2-> ");
    scanf("%d %d %d", &m2.ora, &m2.minut, &m2.secunda);

    m3.secunda=m1.secunda+m2.secunda;
    m3.minut=m3.ora=0;
    if(m3.secunda>59)
    {
        m3.secunda-=60;
        m3.minut=1;
    }

    m3.minut+=m1.minut+m2.minut;
    if(m3.minut>59)
    {
        m3.minut-=60;
        m3.ora=1;
    }

    m3.ora+=m1.ora+m2.ora;
    if(m3.ora>23)
    {
        m3.ora-=24;
    }

    printf("\nDupa adunarea celor doua momente se obtine momentul: ");
    if (m3.ora < 10)
        if (m3.ora == 24)
            printf("00:");
        else printf("0%d:", m3.ora);
    else printf("%d:", m3.ora);

    if (m3.minut < 10)
        if (m3.minut == 60)
            printf("00:");
        else printf("0%d:", m3.minut);
    else printf("%d:", m3.minut);

    if (m3.secunda < 10)
        if (m3.secunda == 60)
            printf("00");
        else printf("0%d", m3.secunda);
    else printf("%d", m3.secunda);

    return 0;
}
