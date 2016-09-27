#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool wczytaj_liczbe (ifstream & plik, int & liczba)
{
    plik.clear ();
    plik>>liczba;
    if (plik.fail ())
        return false;

    return true;
}

bool wczytaj_znak (ifstream & plik, char & znak)
{
    //cout<<"4"<<endl;
    plik.clear ();
    plik>>znak;
    if (plik.fail ())
    {
        //cout<<"tu"<<endl;
        return false;
    }
    return true;
}

bool czyNapotkanoZnakNowegoWiersza( std::ifstream & plik )
{
    char cZnak;
    for(;; ) //nieskoñczona pêtla
    {
        //cout<<"5"<<endl;
        plik.clear();
        cZnak = plik.peek(); //sprawdzamy jaki kolejny znak zostanie zwrócony przez operacjê odczytu
        if( plik.fail() || plik.bad() )
             return false; //wyst¹pi³ b³¹d odczytu danych

        if( !isspace( cZnak ) )
             return false; //pobrany znak nie jest bia³ym znakiem

        plik.get( cZnak ); //odczytujemy bia³y znak z pliku
        if( plik.fail() || plik.bad() )
             return false; //wyst¹pi³ b³¹d odczytu danych

        if( cZnak == '\n' )
             return true;

    } //for
}

bool wczytaj_plik (string lokalizacja)
{
    int i=0;
    int liczba;
    char znak;
    int s=0;
    ifstream plik;
    plik.open (lokalizacja.c_str ());
    if (!plik.good ())
        return false;

    //cout<<"1"<<endl;
    while (!plik.eof ())
    {
        znak = '.';
        while (!czyNapotkanoZnakNowegoWiersza(plik))
        {

            //cout <<"2"<<endl;
            if (wczytaj_liczbe(plik, liczba) == true)
            {
                //cout<<"3"<<endl;
                //cout<<liczba<<", ";
                s+=liczba;
            }
            else
            {
                //cout<<"bledne dane w wierszu: "<<i<<endl;
                if (wczytaj_znak (plik, znak))
                {
                    //cout<<znak<<", ";
                    continue;
                }
                else
                {
                    //cout<<"???";
                    break;
                }
            }
        }
        i++;
        if (znak == '.')
        {
            //cout<<endl<<s<<endl;
            cout<<s<<endl;
            s=0;
        }
        else
        {
            cout<<"bledne dane w wierszu nr. "<<i<<endl;
        }
    }
    return true;
}

int main ()
{
     if (!wczytaj_plik ("tekst 5.txt"))
        cout<<"nie udalo sie odczytac pliku"<<endl;

    else
        cout<<"otworzono plik"<<endl;


    return 0;
}
