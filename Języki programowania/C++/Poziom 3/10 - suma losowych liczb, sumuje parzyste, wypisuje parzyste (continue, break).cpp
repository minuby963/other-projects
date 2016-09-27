#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void wpisz_do_tablicy (int t[], int ile)
{
    int s=0;
    for(int i=0;i<ile;i++)
    {
        t[i]=rand ()%30;
        cout<<t[i]<<", ";
        s+=t[i];
    }
    cout<<endl<<endl<<"suma wszystkich: "<<s<<endl<<endl;
}

void wypisz_parzyste (int t[], int ile)
{
    int s=0;
    for(int i = 0; i<ile; i++)
    {
        if (t[i]%2 == 0)
        {
            cout<<t[i]<<", ";
            s=s+t[i];
        }
    }
    cout<<endl<<endl<<"suma parzystych: "<<s<<endl<<endl;

}




int main ()
{
    srand (time (0));
    int tablica [10];
    wpisz_do_tablicy(tablica, 10);
    cout<<endl<<endl;
    wypisz_parzyste(tablica, 10);

    return 0;
}
