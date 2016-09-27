#include <iostream>
int main()
{
    int liczba;
    do
    {
        std::cout << "Podaj liczbe 123 aby zakonczyc petle" << std::endl;
        std::cin >> liczba;
        std::cout << "Podales liczbe " << liczba << std::endl;
    } while( liczba != 123 );

    std::cout << "Koniec" << std::endl;
    return 0;
}
