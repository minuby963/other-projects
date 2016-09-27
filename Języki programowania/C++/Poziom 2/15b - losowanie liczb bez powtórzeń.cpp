#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int losuje (int t[], int ile)
{
int a;
a=(rand()%10)+1;
return a;
}

bool sprawdza (int a, int ile, int t[])
{
int i=0;
if ((ile>=0)&&(ile<10))
{
do
{
if (a==t[i])
return false;

i++;
}
while (i<ile);
return true;
}
else
return false;
}

int wypisz (int t [], int ile)
{
int i=0;
cout<<endl<<endl;
do
{
cout<<t [i]<<", ";
i++;
}
while (i<ile);
}


int main ()
{
int tablica [10];
int b;
int c=0;
int a;
srand (time (0));
b=rand ();
cout<<"liczby losowane z powtorzeniami : "<<endl;
do
{
do
{a = losuje (tablica, 10);
cout<<a<<", ";//liczby z powtorzeniami

}
while (sprawdza (a, c, tablica)==false);
tablica [c] = a;

//cout<<endl<<tablica [c]<<", ";

c++;
}
while (c<10);

wypisz (tablica, 10);

return 0;
}
