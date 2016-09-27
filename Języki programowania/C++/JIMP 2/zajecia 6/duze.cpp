#include <iostream>
#include <fstream>
using namespace std;


class duze
{
public:
    char *wsk;
    int rozmiar;


//********KONSTRUKTOR**********//
    duze()
    {
        wsk=NULL;
        rozmiar=0;
    }
//********KONSTRUKTOR KOPIUJACY**********//
    duze(duze & d)
    {
        int i;
        rozmiar=d.rozmiar;
        this->wsk=new char[rozmiar];
        for(i=0;i<rozmiar;++i)
        {
            this->wsk[i]=d.wsk[i];
        }
    }
//********DESTRUKTOR**********//
    ~duze()
    {
        delete [] wsk;
        wsk=NULL;
    }


//********OPERATOR=**********//
    duze & operator=(const duze & d)
    {
        if(this==&d) return *this;
        int i;
        delete [] wsk;
        wsk=NULL;

        rozmiar=d.rozmiar;
        wsk=new char[rozmiar];
        for(i=0;i<rozmiar;++i)
        {
            wsk[i]=d.wsk[i];
        }
        return *this;
    }
//********OPERATOR+**********//
    duze & operator+(const duze & d)
    {
        int i;
        static duze nowy;
        if(nowy.wsk!=NULL)
        {
            nowy.~duze();
        }
        nowy.rozmiar=((rozmiar > d.rozmiar) ? rozmiar : d.rozmiar);
        cout<<"rozmiar = "<<nowy.rozmiar<<endl;
        nowy.wsk=new char[nowy.rozmiar];

        int tab[nowy.rozmiar];

        if(d.rozmiar==0)
        {
            nowy=*this;
            return nowy;
        }
        if(rozmiar==0)
        {
            nowy=d;
            return nowy;
        }
        else
        {
            i=nowy.rozmiar-1;
            cout<<"i = "<<i<<endl;

            /*while(rozmiar<=i)
            {
                nowy.wsk[i]=d.wsk[i];
                cout<<"nowy1 = "<<nowy.wsk[i]<<endl;
                i--;

            }
            while(d.rozmiar<=i)
            {

                nowy.wsk[i]=wsk[i];
                cout<<"nowy2 = "<<nowy.wsk[i]<<endl;
                i--;
            }
            while(i>=0)
            {
                nowy.wsk[i]=wsk[i]+d.wsk[i];
                cout<<"nowy3 = "<<nowy.wsk[i]<<endl;
                i--;
            }*/
        }

        return nowy;
    }
};


//********OPERATORY WEJSCIA**********//
istream & operator>>(istream & in, duze & d)
{
    const int rozmiar=10;
    int mnoznik=1;
    d.wsk=new char[rozmiar];
    int i=0;
    int j;


    while((in.get(d.wsk[i]))&&(d.wsk[i]!='\n'))
    {
        if(i>=rozmiar*mnoznik-1)
        {
            char array[rozmiar*mnoznik];
            for(j=0;j<rozmiar*mnoznik;++j)
            {
                array[j]=d.wsk[j];
            }
            delete [] d.wsk;
            d.wsk=NULL;
            d.wsk=new char[(mnoznik+1)*rozmiar];
            for(j=0;j<rozmiar*mnoznik;++j)
            {
                d.wsk[j]=array[j];
            }
            mnoznik++;
            //cout<<"rozmiar = "<<rozmiar*mnoznik<<endl;
        }
        i++;
        //cout<<"i = "<<i<<endl;
    }

    d.rozmiar=i;
    if(i!=mnoznik*rozmiar-1)
    {
        char array[rozmiar*mnoznik];
        for(j=0;j<rozmiar*mnoznik;++j)
        {
            array[j]=d.wsk[j];
        }
        delete [] d.wsk;
        d.wsk=NULL;
        d.wsk=new char[i];
        for(j=0;j<i;++j)
        {
            d.wsk[j]=array[j];
        }
    }
    return in;
}
//********OPERATORY WYJSCIA**********//
ostream & operator<<(ostream & out, duze & d)
{
    int i=0;
    while(i<d.rozmiar)//d.wsk[i]!='\0')//i<200)
    {
        out<<d.wsk[i];
        i++;
    }
    return out;
}


int main()
{
    duze d1, d3;
    cout<<"Podaj 1 liczbe: "<<endl;
    cin>>d1;
    duze d2(d1);
    cout<<"Podaj 2 liczbe: "<<endl;
    cin>>d2;
    cout<<"D1: "<<endl<<d1<<endl;
    cout<<"D2: "<<endl<<d2<<endl;

    d3=d1+d2;

    cout<<"D1: "<<endl<<d1<<endl;
    cout<<"D2: "<<endl<<d2<<endl;
    cout<<"D3: "<<endl<<d2<<endl;


    return 0;
}
