#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool wczytuj_plik (string lokalizacja_pliku, string t[], int & c)
{
    ifstream plik;
    plik.open (lokalizacja_pliku.c_str () );
    if(!plik.good ())
        return false;

    for (int i=0; getline (plik, t[i]); i++)
    {
        getline (plik, t[i]);
        c++;
        //cout<<c<<endl;
    }

    plik.close ();

    /*
    string a;
    int c;
    while (getline (plik, a))
    {
        c++;
    }
    cout<<c<<endl;
    */
}

bool sprawdz (string & wyraz, string & tablica)
{
    size_t b = tablica.find (wyraz);
    if (b == string::npos)
        return false;
    else
        return true;
}



int main ()
{
    string tablica [50];
    int c = 0;
    if (wczytuj_plik("tekst 2.txt", tablica, c) == false)
    {
        cout<<"nie udalo sie wczytac pliku"<<endl;
    }

    for (int i = 0; i<=c; i++ )
        cout<<tablica [i]<<endl;

    cout<<endl<<endl<<endl;
    string wyraz;
    cout<<"podaj wyraz"<<endl;
    cin>>wyraz;

    for(int j=0; j<=c; j++)
    {
        if (sprawdz(wyraz, tablica [j]) == true)
            cout<<tablica [j]<<endl;
    }

    return 0;
}
