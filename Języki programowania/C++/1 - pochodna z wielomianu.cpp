#include <iostream>
using namespace std;
int main ()
{
    char znak;
    int i=0;
    int wykladnik;
    int liczba;
    cout<<"podaj wielomian z niewiadoma x"<<endl;
    while (i<10)
    {
        cin>>liczba;
        if (cin.good ())
        {
            cout<<liczba<<endl;
        }
        else
        {
            cin>>znak;
            if (znak == 'x')
            {
                cout<<znak<<endl;
            }
        }

        cin>>wykladnik;
        cout<<wykladnik<<", ";
        i++;
    }
    return 0;
}
