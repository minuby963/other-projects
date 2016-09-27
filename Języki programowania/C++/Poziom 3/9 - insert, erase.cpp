#include <iostream>
#include <string>
using namespace std;

std::string konwertuj( std::string & sTekst )
{
    std::string sWynik;

    sWynik = "[b] [/b] [b]";

    sWynik.insert (3,sTekst,3,7);
    sWynik.insert (16, sTekst,16,26);
    sWynik.insert (45, sTekst,43,2);

    sWynik.erase (23, 6);
    sWynik.erase (30,6);

    return sWynik;
}
int main()
{
    std::string tekst = "<b>to jest </b> testowy       napis     <b>:)";
    cout<<tekst.size ()<<endl;
    std::cout << konwertuj( tekst ) << std::endl;
    return 0;
}
