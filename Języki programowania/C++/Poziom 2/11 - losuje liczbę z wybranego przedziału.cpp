#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int wylosuj(int start, int stop)
{
    int a, b;

    a=rand();
    b=rand();

    return (b%(stop-start+1))+start;

}

int main()
{
    srand( time( NULL ) );
    int start;
    cout<<"podaj start"<<endl;
    std::cin >> start;
    int stop;
    cout<<"podaj stop"<<endl;
    std::cin >> stop;
    cout<<endl<<endl<<endl;
    int ile = 20;
    do
    {
        std::cout << wylosuj( start, stop ) << std::endl;
        ile--;
    } while( ile > 0 );

    return 0;
}
