#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int wylosujLiczby(int t[], int pojemnosc_tablicy, int poczatkowa_losowana_liczba, int koncowa_losowana_liczba)
{
    srand(time(NULL));
    int a=0;
    int b;
    b=rand();

    do
    {
        t[a]=(rand()%(koncowa_losowana_liczba-poczatkowa_losowana_liczba))+poczatkowa_losowana_liczba+1;
        a++;
    }
    while(a<pojemnosc_tablicy);

}

int wypiszLiczby (int t[], int pojemnosc_tablicy)
{
    int a=0;

    do
    {
        cout<<t[a]<<endl;
        a++;

    }
    while(a<pojemnosc_tablicy);

}

int obliczSume (int t[], int pojemnosc_tablicy)
{
    int a=0;
    int c=0;

    do
    {
        c=c+t[a];
        a++;
    }
    while(a<pojemnosc_tablicy);

    return c;
}

int main()
{
    int tablica[ 999 ];
    wylosujLiczby( tablica, 999, 4, 10 );
    wypiszLiczby( tablica, 999 );
    int iSuma = obliczSume( tablica, 999 );
    std::cout << "Suma liczb wynosi: " << iSuma << std::endl;
    return 0;
}
