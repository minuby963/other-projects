#include <stdio.h>
#include <string.h>

struct unia
{
    char imie[20];
    char nazwisko[20];
    char tytul[20];
    int nr;
    int cena;
};

int main ()
{
    int i;
    struct unia tab[3];
    for(i=0;i<3;i++)
    {
        printf("podaj imie nr. %d\n", i+1);
        scanf("%s", tab[i].imie);
        printf("podaj nazwisko nr. %d\n", i+1);
        scanf("%s", tab[i].nazwisko);
        printf("podaj tytul nr. %d\n", i+1);
        scanf("%s", tab[i].tytul);
        printf("podaj numer nr. %d\n", i+1);
        scanf("%d", &tab[i].nr);
        printf("podaj cena nr. %d\n", i+1);
        scanf("%d", &tab[i].cena);
    }
    printf("\nimiona to:\n");
    for(i=0;i<3;i++)
    {
        printf("%s, ", tab[i].imie);
    }
    printf("\nnazwiska to:\n");
    for(i=0;i<3;i++)
    {
        printf("%s, ", tab[i].nazwisko);
    }
    return 0;
}

