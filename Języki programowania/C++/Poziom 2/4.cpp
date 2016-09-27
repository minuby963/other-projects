#include <iostream>
using namespace std;

int main ()
{
    int modyfikowana_liczba;
    cout<<"podaj liczbe do modyfikowania"<<endl;
    cin>>modyfikowana_liczba;

    if(modyfikowana_liczba != 0)
    {
        cout<<"instrukcja: "<<endl<<"1 - dodawanie"<<endl<<"2 - odejmowanie"<<endl<<"3 - mno¿enie"<<endl;
        cout<<"4 - dzielenie"<<endl<<"5 - rezygnuj"<<endl;

        do
        {
            int dzialanie;
            cout<<"wybierz dzialanie"<<endl;
            cin>>dzialanie;

            if((dzialanie > 0) && (dzialanie < 5))
            {
                int liczba_modyfikujaca;
                cout<<"podaj liczbe modyfikujaca rozna od 0"<<endl;
                cin>>liczba_modyfikujaca;
                if(liczba_modyfikujaca != 0)
                {
                    switch(dzialanie)
                    {
                        case 1:
                        modyfikowana_liczba = modyfikowana_liczba + liczba_modyfikujaca;
                        cout<<modyfikowana_liczba<<endl;
                        break;

                        case 2:
                        modyfikowana_liczba = modyfikowana_liczba - liczba_modyfikujaca;
                        cout<<modyfikowana_liczba<<endl;
                        break;

                        case 3:
                        modyfikowana_liczba = modyfikowana_liczba * liczba_modyfikujaca;
                        cout<<modyfikowana_liczba<<endl;
                        break;

                        case 4:
                        modyfikowana_liczba = modyfikowana_liczba / liczba_modyfikujaca;
                        cout<<modyfikowana_liczba<<endl;
                        break;

                        defalut:
                        cout<<"nie ma takiego dzilania"<<endl;
                        break;
                    }
                }

            }
            else
            modyfikowana_liczba = 0;

        }
        while(modyfikowana_liczba != 0);
    }
return 0;
}



















