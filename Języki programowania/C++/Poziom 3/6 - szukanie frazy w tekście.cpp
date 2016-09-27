#include <iostream>
#include <string>
using namespace std;

void szukaj_frazy (string & a, string fraza)
{
    size_t b = a.find (fraza);
    if (b == string::npos)
    {
        cout<<"nie ma takiej frazy"<<endl;
        return;
    }

    do
    {
        cout<<"fraza na pozycjach: "<<b<<endl;
        b = a.find (fraza, b+fraza.size());
    }
    while (b != string::npos);
}

int main ()
{
    string a;
    cout<<"podaj tekst"<<endl;
    getline (cin, a);
    cout<<a.size ()<<endl;
    cin.clear ();
    cin.sync ();

    string fraza;
    cout<<"podaj szukana fraze"<<endl;
    cin>>fraza;

    szukaj_frazy(a, fraza);
    return 0;

}
