#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void sprawdz (string nazwa_pliku)
{
    int a;
    int b;
    ifstream plik;
    plik.open (nazwa_pliku.c_str ());
    plik.clear ();
    if (!plik.good ())
        cout<<"blad"<<endl;

    int i=0;
    while (i<4)
    {

        plik >> a;
        if(plik.fail())
            cout<<"blad"<<endl;


        cout<<a<<endl;
        plik.clear ();
        i++;
    }



}

int wczytaj ()
{

}


int main ()
{

    sprawdz("tekst 4.txt");



    return 0;
}
