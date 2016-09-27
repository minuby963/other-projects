#include <iostream>
using namespace std;

void moja_funkcja()
{
    std::cout << "[1] - dodawanie" << std::endl;
    std::cout << "[2] - odejmowanie" << std::endl;
    std::cout << "[0] - wyjscie z programu" << std::endl;
}

int dodawanie(int a,int b)
{
    cout<<a+b<<endl;
}

int odejmowanie(int a,int b)
{
    cout<<a-b<<endl;
}

int main()
{
    std::cout << "W programie sa dostepne nastepujace opcje:" << std::endl;
    moja_funkcja();
    std::cout << "Zycze przyjemnego korzystania z programu" << std::endl << std::endl;


    int a;
    int b;
    int liczba;
    do
    {
        moja_funkcja();

        cout<<"podaj a"<<endl;
        cin>>a;
        cout<<"wybierz dzialanie"<<endl;
        std::cin >> liczba;

        cout<<"podaj b"<<endl;
        cin>>b;

        switch( liczba )
        {
        case 1:
            dodawanie(a,b);
            break;
        case 2:
            odejmowanie(a,b);
            break;
            default:
            break;
        } //switch
    } while( liczba != 0 );

    return 0;
}
