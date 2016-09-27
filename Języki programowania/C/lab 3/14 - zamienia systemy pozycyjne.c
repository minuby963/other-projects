#include <stdio.h>

//
//
//
//




//nie dziala




//
//
//
//
int dziesiec_do (int x)
{
    int i;
    if (x==0)
        return 1;
    int potega=1;
    for(i=1; i<=x;i++)
    {
        potega=potega*10;
    }
    return potega;
}
/*
int zeruje_tablice (int tablica [])
{   printf("zero?");
    int w;
    for(w=0;w<10;w++)
    {
        tablica[w]=0;
    }
}

int z_dziesietnego (int liczba, int system, int tablica [10])
{
    int a;
    int i=0;
    int wynik=0;
    int potega;
    while (liczba>=system)
    {
        printf("a n");
        /*a=liczba%system;

        if (i==0)
        {
            wynik=a*dziesiec_do (i);
        }
        else
        {
            wynik=wynik + a*dziesiec_do (i);
        }
        printf("dziesiec_do (i) = %d\n",dziesiec_do (i));
        printf("wynik = %d\n",wynik);
        liczba=liczba/system;
        printf("podzielona liczba = %d\n",liczba);
        tablica [i]=liczba%system;
        printf("b");
        i++;
        liczba=liczba/system;
    }
    //return i;
}
*/

int main ()
{
    int liczba;
    int system;
    int t;
    int i=0;
    int tablica [10];
    printf("podaj liczbe\n");
    scanf("%d",&liczba);
    printf("podaj w jakim jest systemie\n");
    scanf ("%d",&system);
    printf("w systemie %d liczba %d wynosi: ", system, liczba);

    for (;i<10;i++)
        tablica[i]=3;
    i=0;
    while (liczba*system>=system)
    {
        i++;
        liczba=liczba/system;
        tablica [i]=liczba%system;
        printf("%d",tablica [i]);
    }
    printf("\n");

    //printf("%d\n",i);
    /*
    tablica[5]=7;
    printf("%d",tablica[5]);
    //z_dziesietnego (liczba,system,tablica [10]);
    //zeruje_tablice (tablica [10]);
    //i=z_dziesietnego (liczba, system, tablica [], i);
    for(t=10;t>10-i;t--)
    {
        printf("%d",tablica [t]);
    }
    //printf("w systemie %d liczba %d wynosi \n\n\n%d\n\n\n", system, liczba, z_dziesietnego (liczba, system));
    */
    return 0;
}
