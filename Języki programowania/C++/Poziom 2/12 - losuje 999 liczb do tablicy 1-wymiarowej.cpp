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
Napisz program, który wylosuje 999 liczb ca³kowitych z zakresu od 4 do 10 w³¹cznie,
wypisze te wartoœci na ekran, po czym zsumuje je i wynik wypisze na ekran.
Program ma wykorzystywaæ tablicê, która zostanie najpierw wype³niona liczbami losowymi z okreœlonego przedzia³u,
a nastêpnie wynik zostanie obliczony na podstawie zawartoœci ca³ej tablicy. */


