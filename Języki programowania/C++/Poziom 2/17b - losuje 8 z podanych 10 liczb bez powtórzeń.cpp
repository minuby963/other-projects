#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool sprawdz (int t[], int a, int ile)
{
    int i=0;
    if((ile<=0)&&(ile>10))
        return false;

    else
    {
        do
        {
            if (t[i] == a)
            return false;

            i++;
        }
        while (i<ile);
        return true;
    }
}

int losuj ()
{
    int a;
    a=(rand () % 10);
    return a;
}

int wypisz (int t1 [], int t2 [])
{
    int i=0;
    do
    {
        cout<<t2 [t1 [i]]<<", ";
        i++;
    }
    while (i<8);
}

int main ()
{
    srand ( time (0) );
    int a;
    int b;
    int c;
    int i=0;
    int ile=0;
    b=rand ();
    int tablica1 [8];
    int tablica2 [10];
    do
    {
        do
        {
            a=losuj ();
            //cout<<a<<", ";
        }
        while (sprawdz (tablica1, a, ile) == false);
        tablica1 [ile] = a;
        ile++;
    }
    while (ile<8);
    //cout<<endl<<endl<<endl;
    do
    {
        //cout<<tablica1 [i]<<", ";
        i++;
    }
    while (i<8);
    //cout<<endl<<endl<<endl;

    i=0;
    ile=0;
    do
    {
        cout<<"podaj liczbe nr. "<<i+1<<endl;
        cin>>tablica2 [ile];
        i++;
        ile++;

    }
    while (ile<10);

    cout<<endl<<endl<<"wylosowane liczby to: "<<endl<<endl;

    wypisz (tablica1, tablica2);

    cout<<endl<<endl<<endl;


    return 0;
}
