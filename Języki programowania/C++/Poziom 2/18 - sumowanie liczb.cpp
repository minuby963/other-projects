#include <iostream>
using namespace std;

int wczytaj (int t [], int ile)
{
    for (int i=0; i<ile; i++)
    {
        cout<<"podaj liczbe nr. "<<i+1<<endl;
        cin>>t [i];
    }
}

int sumuj (int t [], int ile)
{
    int suma=0;
    int i;
    do
    {
        suma=suma + t[i];
        i++;
    }
    while (i<ile);
    return suma;
}


int main ()
{
    int tablica [5];
    wczytaj (tablica, 5);
    cout<<sumuj (tablica, 5);


}
