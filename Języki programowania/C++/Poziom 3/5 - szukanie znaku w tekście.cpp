#include <iostream>
#include <string>
using namespace std;

void szukaj_znaku (string & a, char znak)
{
    size_t b = a.find (znak);
    if (b == string::npos)
    {
        cout<<"nie ma takiego znaku"<<endl;
        return;
    }

    do
    {
        cout<<"znak na pozycji: "<<b<<endl;
        b = a.find (znak, b + 1);
    }
    while (b != string::npos);
}



int main ()
{
    string a = "abcdefghijklmnoprstquwxyz  abcdefghijklmnoprstquwxyz  abcdefghijklmnoprstquwxyz  abcdefghijklmnoprstquwxyz";
    char znak;
    cout<<"podaj znak"<<endl;
    cin>>znak;
    szukaj_znaku(a,znak);
    return 0;
}
