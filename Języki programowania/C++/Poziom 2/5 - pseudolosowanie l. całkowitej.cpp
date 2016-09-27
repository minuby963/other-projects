

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand( time( NULL ) );
    int a;
    int b;
    a=rand()%100;
    b=rand();
    cout<<b%100<<endl;

    return 0;
}

/*
#include <iostream>
#include <cstdlib>
#include <ctime>
int main()
{
    srand( time( NULL ) );
    std::cout << "Wylosowanie pierwsze: " << std::rand() << std::endl;
    int liczba = std::rand();
    std::cout << "Wylosowanie drugie: " << liczba << std::endl;
    liczba = std::rand();
    std::cout << "Wylosowanie trzecie: " << liczba << std::endl;
    return 0;
}
*/
