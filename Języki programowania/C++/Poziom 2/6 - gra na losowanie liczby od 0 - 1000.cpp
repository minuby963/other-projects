#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main ()
{
    int a, b, c, d;
    srand (time(NULL));
    a=rand();
    b=(rand()%1000)+1;
    d=1;
    do
    {
        cout<<"zgaduj (liczby od 1 - 1000) "<<endl;
        cin>>c;
        if(c!=b)
        {
            if(c>b)
            {
                cout<<"mniejsza"<<endl;
            }
            else
            {
                cout<<"wieksza"<<endl;
            }
            d++;
        }
    }
    while(c != b);

    cout<<"wygrales!!!"<<endl;
    cout<<"ilosc prob = "<<d<<endl;
}


/*
Twoim zadaniem domowym jest napisanie prostej gry, kt�ra ma dzia�a� nast�puj�co:
1. Program losuje liczb� z przedzia�u od 1 do 1000.
2. U�ytkownik zgaduje liczb�, kt�ra zosta�a wylosowana.
3. Je�eli podana liczba jest za du�a (za ma�a) gra wypisuje stosowny komunikat i powraca do kroku 2.
4. Je�eli gracz trafi liczb� wylosowan� to progam ko�czy dzia�anie, wypisuj�c na ekran wylosowan� liczb� oraz liczb� 'strza��w', kt�re odda� gracz.
Gra ma by� zabezpieczona przed mo�liwo�ci� wprowadzenia b��dnych warto�ci liczbowych.
*/
