#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool wczytaj_dane (string nazwa_pliku)
{
    ifstream plik;
    plik.open ( nazwa_pliku.c_str () );
    if (plik.good ()== false)
        return false;

    string a;

    while (getline (plik, a))
    {
        cout<<a<<endl;
    }

    plik.close ();
    return true;

}

int main ()
{
    if (wczytaj_dane("tekst 1.txt") == false)
        cout<<"nie udalo sie wczytac piku"<<endl;

    return 0;
}
