#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

class tlumacz
{
private:
    map<string, string> ang_pl;

public:
    tlumacz()
    {
        ang_pl["i"]="ja";
        ang_pl["you"]="ty";
    }

    void wypisz()
    {

        string jezyk;
        cout<<"podaj z jakiego jezyka na jaki jezyk chcesz wypisac (ang lub pl): "<<endl;
        cin>>jezyk;
        cout<<endl<<endl;

        system("cls");
        //printf("\033[2J");

        if(jezyk=="ang")
        {
            for(map<string,string>::iterator i=ang_pl.begin();i!=ang_pl.end();i++)
                cout<<i->first<<" - "<<i->second<<endl;
        }
        else
        {
            if(jezyk=="pl")
            {
                for(map<string,string>::iterator i=ang_pl.begin();i!=ang_pl.end();i++)
                    cout<<i->second<<" - "<<i->first<<endl;
            }
            else
                cout<<"Program nie obsugluje tego jezyka!"<<endl;
        }
        cout<<endl;
    }

    void szukaj()
    {
        string jezyk, wyraz;
        int it=0;
        int it2=0;
        cout<<endl<<"Podaj jezyk w ktorym chcesz wyszukac wyraz (ang lub pl): "<<endl;
        cin>>jezyk;

        system("cls");
        //printf("\033[2J");

        if(jezyk!="pl" && jezyk != "ang")
        {
            cout<<"Program nie obsugluje tego jezyka!"<<endl;
            return;
        }
        cout<<"Podaj szukany wyraz: "<<endl;
        cin>>wyraz;

        if(jezyk=="ang")
        {
            for(map<string,string>::iterator i=ang_pl.begin();i!=ang_pl.end();i++)
            {
                if(wyraz == i->first)
                {
                    cout<<endl;
                    cout<<i->first<<" - "<<i->second<<endl;
                    return;
                }
            }
            for(map<string,string>::iterator i=ang_pl.begin();i!=ang_pl.end();i++)
            {
                while(wyraz[it] == i->first[it])
                {
                    ++it;
                }
                if(it!=0)
                {
                    if(it2==0)
                        cout<<endl<<"Podobne wyrazy: "<<endl;

                    if(wyraz[it-1]==i->first[it-1])
                        cout<<i->first<<" - "<<i->second<<endl;

                    if(it2==10)
                        return;

                    ++it2;
                }
            }
        }
        else
        {
            for(map<string,string>::iterator i=ang_pl.begin();i!=ang_pl.end();i++)
            {
                if(wyraz == i->second)
                {
                    cout<<endl;
                    cout<<i->second<<" - "<<i->first<<endl;
                    return;
                }
            }
            for(map<string,string>::iterator i=ang_pl.begin();i!=ang_pl.end();i++)
            {
                while(wyraz[it] == i->second[it])
                {
                    ++it;
                }
                if(it!=0)
                {
                    if(it2==0)
                        cout<<endl<<"Podobne wyrazy: "<<endl;

                    if(wyraz[it-1]==i->second[it-1])
                        cout<<i->second<<" - "<<i->first<<endl;

                    if(it2==10)
                        return;

                    ++it2;
                }
            }

        }
        if(it2==0)
            cout<<"Nie ma tego wyrazu w bazie"<<endl;
    }

    void dopisz()
    {
        string ang;
        string pl;
        int i;

        cout<<"podaj wyraz w jezuku angielskim: "<<endl;
        cin>>ang;
        try
        {
            for(i=0;i<ang.length();i++)
            {
                if(!isalpha(ang[i]))
                {
                    string err="Ktorys ze znakow nie jest litera!";
                    throw err;
                }
            }
        }
        catch(string err)
        {
            cout<<err<<endl;
            return;
        }
        for(i=0;i<ang.length();i++)
        {
            ang[i]= tolower( ang[i] );
        }

        cout<<"podaj wyraz w jezuku polskim: "<<endl;
        cin>>pl;
        try
        {
            for(i=0;i<pl.length();i++)
            {
                if(!isalpha(pl[i]))
                {
                    string err="Ktorys ze znakow nie jest litera!";
                    throw err;
                }
            }
        }
        catch(string err)
        {
            cout<<err<<endl;
            return;
        }
        for(i=0;i<pl.length();i++)
        {
            pl[i]= tolower( pl[i] );
        }
        ang_pl [ang]=pl;

        system("cls");
        //printf("\033[2J");
        cout<<"Dopisano wyraz"<<endl;
    }

    void pobierz()
    {
        ifstream plik;
        int liczba;
        string ang, pl, tmp;
        //plik.open("dane.txt");
        //if(!plik.good())
            //cout<<"Nie udalo sie otworzyc pliku!"<<endl;
        try
        {
            plik.open("dane.txt");
            string err="Nie udalo sie otworzyc pliku!";
            if(!plik.good())
                throw err;
        }
        catch(string err)
        {
            cout<<err;
            return;
        }

        while(true)
        {
            plik >> liczba;
            plik >> ang;
            plik >> pl;
            getline(plik, tmp);
            if(plik.good())
            {
                ang_pl[ang]=pl;
            }
            else
                break;

        }
        plik.close();


        system("cls");
        //printf("\033[2J");
        cout<<"Pobrano dane z pliku"<<endl;
    }
};

void menu1()
{
    cout<<endl;
    cout<<"================================="<<endl;
    cout<<"0 - Zakoncz program"<<endl;
    cout<<"1 - Wypisz wszystkie wyrazy"<<endl;
    cout<<"2 - Dopisz wyraz"<<endl;
    cout<<"3 - Szukaj wyrazu"<<endl;
    cout<<"4 - Pobierz dane z pliku"<<endl;
    cout<<"================================="<<endl<<endl;
}

int main()
{
    tlumacz tl;
    int menu=1;
    while(menu!=0)
    {
        menu1();
        cout<<"podaj numer: ";
        cin>>menu;
        switch(menu)
        {
            case 1:
                tl.wypisz();
                break;
            case 2:
                tl.dopisz();
                break;
            case 3:
                tl.szukaj();
                break;
            case 4:
                tl.pobierz();
                break;
            default:
                continue;
                break;
        }
    }

    return 0;
}
