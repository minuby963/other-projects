#include <iostream>
using namespace std;

int wpisuj (int t[],int ile)
{
    for (int i=0; i<ile; i++)
    {
        t[i]=1+(5*i);
    }
}

int main ()
{
    int tablica [20];
    wpisuj (tablica, 20);
    for(int i=0; i<20; i++)
    {
        cout<<tablica [i]<<", ";
    }
    return 0;
}
