#include <iostream>
#include <stdio.h>
#include "headers.hpp"

using namespace std;

int main()
{
    lista<macierze> a;
    lista<macierze> b;
    lista<macierze> c;

    cout<<"lista a: pierwszy parametr to rozmiar macierzy"<<endl;
    cin>>a;
    cout<<"lista a: pierwszy parametr to rozmiar macierzy"<<endl;
    cin>>a;
    cout<<"lista a: pierwszy parametr to rozmiar macierzy"<<endl;
    cin>>a;

    cout<<"lista b: pierwszy parametr to rozmiar macierzy"<<endl;
    cin>>b;
    cout<<"lista b: pierwszy parametr to rozmiar macierzy"<<endl;
    cin>>b;

    c=a+b;
    c=a+b;
    cout<<endl<<"////////// A: //////////"<<endl<<endl<<a<<endl;
    cout<<"////////// B: //////////"<<endl<<endl<<b<<endl;
    cout<<"////////// C: //////////"<<endl<<endl<<c<<endl;

    c.sort();
    cout<<"////////// sorted C: //////////"<<endl<<endl<<c<<endl;

    return 0;
}
