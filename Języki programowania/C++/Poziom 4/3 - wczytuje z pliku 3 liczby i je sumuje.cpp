#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool wczytuj (int t[], int & c, string nazwa_pliku)
{
    ifstream plik;
    int s=0;
    plik.open (nazwa_pliku.c_str ());
    if (!plik.good ())
    {
        return false;
    }
    else
    {
        while (!plik.eof ())
        {
            //cout<<plik.good ()<<endl;
            plik>>t[c];
            //cout<<c<<", ";
            //s+=t[c];
            c++;
        }
        //cout<<endl<<s<<endl;
        plik.close ();
        return true;
    }
}

int main()
{
    int c=0;
    int s=0;
    int tablica [50];
    if (wczytuj(tablica, c, "tekst 3.txt") == true)
    {
        c=0;
        wczytuj(tablica, c, "tekst 3.txt");
        for (int i=0; i<c; i++)
        {
            cout<<tablica [i]<<", ";
            s+=tablica[i];
        }
        cout<<endl<<endl<<"suma: "<<s<<endl;
    }
    else
        cout<<"nie mozna wczytac pliku"<<endl;
    return 0;
}
