#include <iostream>
using namespace std;

int wczytajLiczbe()
{
    int a;
    do
    {

        cout<<"podaj liczbe"<<endl;
        cin>>a;
    }
    while(a<=0);

    return a;
}

int main()
{
    std::cout << "Podaj liczbe: ";
    int liczba = wczytajLiczbe();
    std::cout << "Podales liczbe: " << liczba << std::endl;
    return 0;
}
