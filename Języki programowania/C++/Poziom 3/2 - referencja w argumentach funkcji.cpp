#include <iostream>
using namespace std;

int wypisz (int & a)

{
    a=a++;
    cout<<a<<endl<<endl;

}



int main ()
{
    int i;
    int a;
    cout<<"podaj liczbe "<<endl;
    cin>>a;
    cout<<a<<endl<<endl;
    wypisz (a);
    cout<<a<<endl<<endl;
    return 0;

}

