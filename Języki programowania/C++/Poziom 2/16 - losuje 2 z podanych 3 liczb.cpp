#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int wczytuj_liczby ()
{
    int a;
    int i=0;

}

int main ()
{
    srand (time (0));
    int b;
    b=rand ();
    int c;
    int d;
    do
    {
        c=(rand () % 3);
        d=(rand () % 3);

    }
    while (c == d);

    int a;
    int i=0;
    int tablica [3];
    do
    {
        cout<<"podaj liczbe "<<endl;
        cin>>tablica [i];
        i++;
    }
    while (i<3);
    cout<<"losuje z liczb: ";
    i=0;
    do
    {
        cout<<tablica [i]<<", ";
        i++;
    }
    while (i<3);
    cout<<endl<<endl;

    cout<<"pierwsza liczba to: "<<tablica [c]<<endl;
    cout<<"druga liczba to: "<<tablica [d]<<endl;

    return 0;
}
