#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


int losowanie_liczb (int t[], int ilosc, int poczatek, int koniec)
{
    srand (time(NULL));
    int a;
    int i=0;
    int b;
    a=rand ();
    t[i]=(rand()%(koniec - poczatek+1))+poczatek;
    i++;
    do
    {
        do
        {
            b=(rand()%(koniec - poczatek+1))+poczatek;
        }
        while (t[i-1] == b);

        t[i]=b;
        i++;
    }
    while(i<ilosc);
}

int wypisywanie_liczb (int t[], int ilosc)
{
    int i=0;
    do
    {
        cout<<t[i]<<", ";
        i++;
    }
    while(i<ilosc);
}


int main ()
{
    int tablica[10];

    losowanie_liczb(tablica, 10, 1, 10);
    wypisywanie_liczb(tablica, 10);
    return 0;
}
