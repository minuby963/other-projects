#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool sprawdz (ifstream & plik, int & a)
{
    plik.clear ();
    plik>>a;
    if (!plik.good ())
        return false;

    else
        return true;

    /*
    int i=0;
    while (i<10)
    {

        plik >> a;
        if(plik.fail())
        {
            cout<<"blad"<<endl;
            i++;
            continue;

        }
        cout<<a<<endl;
        plik.clear ();
        i++;
    }

    */

}

int wczytaj (int & a, ifstream & plik)
{
    while (!plik.eof ())
   {
       if (sprawdz(plik, a)== true)
            plik >> a;
            cout<<a<<", ";
   }


}


int main ()
{
    int a;
    ifstream plik;
    plik.open ("tekst 4.txt");
    if (plik.fail ())
        cout<<"blad podczas otwierania pliku"<<endl;
    wczytaj (a, plik);



    return 0;
}
