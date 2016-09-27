#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int losuje(int poczatek, int koniec)
{
    int a;
    a=(rand()%(koniec - poczatek + 1)+poczatek);

    return a;

}

bool sprawdza_czy_losowac (int t[], int ile, int poczatek, int koniec, int a)
{

    int i=0;
    do
    {
        if(a==t[i])
        {
            return true;
        }
    }
    while (i<ile);
return false;

}

int wyswietla (int t[], int ile)
{
    int i=0;
    do
    {
        cout<<t[i]<<", ";
        i++;
    }
    while(i<ile);
}


int main()
{
    int tablica[10];
    srand(time(NULL));
    int a;
    int b;
    b=rand();

    int i=0;

    do
    {
        cout<<1;
        do
        {
            a=losuje (1, 10);
        }
        while (sprawdza_czy_losowac(tablica, 10, 1, 10, a) == true);

        a=tablica[i];

        i++;


    }
    while (i<10);

    wyswietla(tablica, 10);




    return 0;

}

