#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int losuj (int t[], int ile)
{
    for (int i=0; i< ile; i++)
    {
        t [i] = (rand ()%20)+11;
    }
}

int wypisuj_od_poczatku (int t [], int ile)
{
    for(int i=0;i<ile; i++)
    {
        cout<<t[i]<<", ";
    }
}

int wypisuj_od_konca (int t [], int ile)
{
    for(int i=ile-1;i>=0; i--)
    {
        cout<<t[i]<<", ";
    }
}

int znajduje_najwieksza (int t[], int ile)
{
    int i=0;
    int j=0;

    for(j;j<ile;j++)
    {
        if (t[i]<t[j])
        {
            i++;
            j=0;
        }
    }
    cout<<t[i];
    return t[i];
}

int znajduje_najmniejsza (int t[], int ile)
{
    int i=0;
    int j=0;
    //"i" z "j" odwrotnie ni¿ w "znajduje_najmniejsza"
    for(i;i<ile;i++)
    {
        if(t[i]<t[j])
        {
            j++;
            i=0;
        }
    }
    cout<<t[j];
}

int main ()
{
    srand (time (0));
    int a;
    int tablica [10];
    a = rand ();

    losuj (tablica, 10);
    cout<<endl<<endl;
    wypisuj_od_poczatku(tablica, 10);
    cout<<endl<<endl;
    wypisuj_od_konca(tablica, 10);
    cout<<endl<<endl;
    znajduje_najwieksza(tablica, 10);
    cout<<endl<<endl;
    znajduje_najmniejsza(tablica, 10);
    cout<<endl<<endl;

    return 0;
}
