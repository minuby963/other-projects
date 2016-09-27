#include <iostream>
int main()
{
    int ile;

    std::cout << "Ile razy wypisac napis? ";
    std::cin >> ile;
    int pozycja = 1;
    if( ile > 0 )
    do
    {
        std::cout << "Napis nr" << pozycja << std::endl;
        pozycja++;
        ile--;
    } while( ile > 0 );

    return 0;
}
