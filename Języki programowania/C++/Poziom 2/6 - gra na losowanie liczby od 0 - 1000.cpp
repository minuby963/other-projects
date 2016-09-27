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
Twoim zadaniem domowym jest napisanie prostej gry, która ma dzia³aæ nastêpuj¹co:
1. Program losuje liczbê z przedzia³u od 1 do 1000.
2. U¿ytkownik zgaduje liczbê, która zosta³a wylosowana.
3. Je¿eli podana liczba jest za du¿a (za ma³a) gra wypisuje stosowny komunikat i powraca do kroku 2.
4. Je¿eli gracz trafi liczbê wylosowan¹ to progam koñczy dzia³anie, wypisuj¹c na ekran wylosowan¹ liczbê oraz liczbê 'strza³ów', które odda³ gracz.
Gra ma byæ zabezpieczona przed mo¿liwoœci¹ wprowadzenia b³êdnych wartoœci liczbowych.
*/
