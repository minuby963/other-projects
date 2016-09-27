#include <stdio.h>

int potega (int i, int system)
{
    int a;
    int wynik = 1;
    if (i==0)
        return 1;
    if (i<0)
        return 0;

    for(a=0;a<i;a++)
    {
        wynik = wynik*system;
    }
    return wynik;
}

int na_dziesietny (int system, int liczba)
{
    int wynik = 0;
    int cyfra=0;
    int zmieniona = 0;
    int i, j=9, k;
    for (i=1;i<=10;i++)
    {
        printf("\n j = %d \n",j);
        if (liczba<j)
            break;
        j=j*10 +j;

    }
    printf("\n i = %d \n", i);
    for(k=0;k<i;k++)
    {
        if (k==0)
            cyfra = liczba%potega (k+1, 10);
        else
            cyfra = (liczba%potega (k+1,10) - liczba%potega (k,10))/potega (k,10);
        printf ("cyfra = %d\n",cyfra);
        zmieniona = cyfra * potega(k,system);
        printf ("zmieniona = %d\n",zmieniona);
        wynik = wynik + zmieniona;
        //wynik =wynik + ((liczba%dziesiec_do (k+1))*(system*dziesiec_do (k)) - wynik )/ dziesiec_do (k);
        printf ("wynik = %d\n",wynik);
    }
    return wynik;
}

int main ()
{
    int liczba;
    int system;
    printf("podaj liczbe: ");
    scanf("%d",&liczba);
    printf("podaj system: ");
    scanf("%d",&system);
    printf("\n %d \n",na_dziesietny (system, liczba) );

    return 0;
}
