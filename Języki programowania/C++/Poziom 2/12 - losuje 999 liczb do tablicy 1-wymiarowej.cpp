#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    int tablica [1000];
    int a=0;
    int b;
    int c;
    srand (time(NULL));

    b=rand();

    do
    {
        tablica[a]=(rand()%6)+5;
        a++;
    }
    while(a<1000);

    a=0;

    do
    {
        cout<<tablica[a]<<endl;
        a++;
    }
    while(a<1000);

    c=0;
    a=0;
    cout<<endl<<endl<<endl;

    do
    {
        c=c+tablica[a];
        a++;
    }
    while(a<1000);
    cout<<c<<endl;

    return 0;
}
/* Zadanie domowe
Napisz program, kt�ry wylosuje 999 liczb ca�kowitych z zakresu od 4 do 10 w��cznie,
wypisze te warto�ci na ekran, po czym zsumuje je i wynik wypisze na ekran.
Program ma wykorzystywa� tablic�, kt�ra zostanie najpierw wype�niona liczbami losowymi z okre�lonego przedzia�u,
a nast�pnie wynik zostanie obliczony na podstawie zawarto�ci ca�ej tablicy. */


