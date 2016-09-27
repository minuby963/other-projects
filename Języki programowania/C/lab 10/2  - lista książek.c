#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct unia
{
    struct unia *adres;
    char imie[30];
    char nazwisko[30];
    char tytul[30];
    int nr;
    int cena;
};

void ksiazka (int *i,struct unia **ppoint)
{
    struct unia *nowy;
    nowy=(struct unia*)malloc(sizeof(struct unia));
    printf("podaj imie nr. %d\n", (*i)+1);
    scanf("%s", nowy->imie);
    nowy->nr=*i+1;

    /*printf("podaj nazwisko nr. %d\n", *i+1);
    scanf("%s", tab[i].nazwisko);
    printf("podaj tytul nr. %d\n", *i+1);
    scanf("%s", tab[i].tytul);
    printf("podaj numer nr. %d\n", *i+1);
    scanf("%d", &tab[i].nr);
    printf("podaj cena nr. %d\n", *i+1);
    scanf("%d", &tab[i].cena);*/

    nowy->adres=*ppoint;
    *ppoint=nowy;
}


void wyswietl (struct unia **ppoint)
{
    struct unia *tmp;
    tmp=*ppoint;
    while (tmp  != NULL)
    {
        printf("ksiazka nr. %2d: %s\n",tmp->nr,tmp->imie);
        tmp=tmp->adres;
    }
}

void wyswietl2 (struct unia **ppoint, int poczatek, int koniec)
{
    struct unia *tmp;
    tmp=*ppoint;
    while (tmp  != NULL)
    {
        if(((tmp->nr)>=poczatek)&&((tmp->nr)<=koniec))
        {
            printf("ksiazka nr. %2d: %s\n",tmp->nr,tmp->imie);
        }
        tmp=tmp->adres;
    }
}

void kolejnosc (struct unia **ppoint)
{
    struct unia *pop=NULL;
    struct unia *akt=*ppoint;
    struct unia *nast=NULL;

    while (akt!=NULL)
    {
        nast=akt->adres;
        akt->adres=pop;
        pop=akt;
        akt=nast;
    }
    (*ppoint)=pop;
}

int main ()
{
    int i;
    int *pi;
    struct unia *point=NULL;
    char znak='t';
    int pocz, kon;

    i=0;
    pi=&i;

    while (znak=='t')
    {
    ksiazka (pi,&point);
    printf("czy chcesz wczytac kolejna ksiazke? (t, n): ");
    scanf("%c",&znak);
    scanf("%c",&znak);
    i=i+1;
    }

    /*printf("podaj zakres ksiazek do wyswietlenia\n");
    printf("poczatkowa: ");
    scanf("%d",&pocz);
    printf("koncowa: ");
    scanf("%d",&kon);*/

    printf("\n");
    wyswietl (&point);
    kolejnosc (&point);
    printf("\nw odpowiedniej kolejnosci: \n");
    wyswietl (&point);

    printf("\npodaj zakres ksiazek do wyswietlenia\n");
    printf("poczatkowa: ");
    scanf("%d",&pocz);
    printf("koncowa:    ");
    scanf("%d",&kon);
    wyswietl2 (&point,pocz,kon);

    return 0;
}
