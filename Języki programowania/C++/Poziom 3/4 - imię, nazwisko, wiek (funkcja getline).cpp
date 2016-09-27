#include <iostream>
#include <string>
using namespace std;
void wczytajOsobe( string & imie,string & nazwisko, int & wiek)
{
    cin.clear ();
    cin.sync ();
    cout<<"podaj imie "<<endl;
    getline (cin, imie);

    cin.clear ();
    cin.sync ();
    cout<<"podaj nazwisko"<<endl;
    getline (cin, nazwisko);

    do
    {
        cin.clear ();
        cin.sync ();
        cout<<"podaj wiek"<<endl;
        cin>>wiek;

    }
    while (cin.good () == false);
}

void wypiszOsobe (string & imie, string & nazwisko, int wiek)
{
    cout<<endl<<endl;
    cout<<imie<<endl;
    cout<<nazwisko<<endl;
    cout<<wiek<<endl;
}



int main()
{
    string imie[ 2 ];
    string nazwisko[ 2 ];
    int wiek[ 2 ];
    for( int i = 0; i < 2; i++ )
         wczytajOsobe( imie[ i ], nazwisko[ i ], wiek[ i ] );

    for( int i = 0; i < 2; i++ )
         wypiszOsobe( imie[ i ], nazwisko[ i ], wiek[ i ] );

    return 0;
}
