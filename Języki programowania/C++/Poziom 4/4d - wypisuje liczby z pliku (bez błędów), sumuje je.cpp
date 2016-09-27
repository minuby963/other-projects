#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool wczytaj_liczbe (ifstream & plik, int & a)
{
    plik.clear ();
    plik >> a;
    if (plik.good ())
    {
        return true;
    }
}

bool wczytaj_znak (ifstream & plik, char & znak)
{
    plik.clear ();
    plik >> znak;
    if (plik.fail())
    {
        //cout<<"fail2"<<endl;
        return false;
    }
    return true;

}

bool wczytaj_plik (string lokalizacja)
{
    int s=0;
    ifstream plik;
    int a;
    char znak;
    plik.open (lokalizacja.c_str ());
    if (plik.fail ())
        return false;

    while (!plik.eof ())
    {
        //plik.clear ();
        if (wczytaj_liczbe(plik, a) == true)
        {
            cout<<a<<endl;
            s+=a;
        }
        else
        {
            if (wczytaj_znak (plik, znak)== true)
            {
                //cout<<"znak"<<endl;
            }
            else
                break;
        }
    }
    cout<<endl<<endl<<s<<endl<<endl;
    plik.close ();
    return true;
}


int main ()
{
    if (wczytaj_plik ("tekst 4.txt") == false)
        cout<<"nie udalo sie otworzyc pliku"<<endl;

    else
        cout<<"otworzono plik"<<endl;

    return 0;
}
