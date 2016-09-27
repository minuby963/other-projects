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
        int i, j;
        int p, k;
        int tmp1, tmp2;
        int suma, reszta=0;

        static duze nowy;
        static duze nowy2;
        if(nowy.wsk!=NULL)
        {
            nowy.~duze();
        }
        nowy.rozmiar=((rozmiar > d.rozmiar) ? rozmiar : d.rozmiar);
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
            k=rozmiar-1;
            p=d.rozmiar-1;
            j=nowy.rozmiar-1;
            while(j>=0)
            {
                if(k>=0)
                    tmp1=wsk[k--];
                else
                    tmp1=0;

                if(p>=0)
                    tmp2=d.wsk[p--];
                else
                    tmp2=0;
                suma=tmp1+tmp2+reszta;
                if(suma<10)
                {
                    nowy.wsk[j]=suma;
                    reszta=0;
                }
                else
                {
                    nowy.wsk[j]=suma%10;
                    reszta=suma/10;
                    if(j==0)
                    {
                        nowy2.~duze();
                        nowy2.rozmiar=nowy.rozmiar+1;
                        nowy2.wsk=new char[nowy2.rozmiar];
                        for(i=nowy.rozmiar-1;i>=0;--i)
                        {
                            nowy2.wsk[i+1]=nowy.wsk[i];
                            nowy2.wsk[0]=reszta;

                        }
                        nowy.~duze();
                        return nowy2;
                    }
                }
                j--;
            }
        }
        return nowy;
    }

//********OPERATOR***********//
    duze & operator*(const duze & d)
    {
        int i, j, k;
        int iloczyn, suma;
        static duze nowy;
        static duze nowy2;
        if(nowy.wsk!=NULL)
        {
            nowy.~duze();
        }

        if((d.rozmiar==0) || (rozmiar==0))
        {
            nowy.wsk=new char[1];
            nowy.wsk[0]=0;
            nowy.rozmiar=1;
            return nowy;
        }
        else
        {
            nowy.rozmiar=rozmiar+d.rozmiar;
            nowy.wsk=new char[nowy.rozmiar];
            for(i=0;i<nowy.rozmiar;i++)
                nowy.wsk[i]=0;

            k=nowy.rozmiar-1;
            for(i=rozmiar-1;i>=0;i--)
            {
                for(j=d.rozmiar-1;j>=0;j--)
                {
                    iloczyn=wsk[i]*d.wsk[j];
                    suma=nowy.wsk[k]+iloczyn;
                    nowy.wsk[k]=(suma)%10;
                    nowy.wsk[k-1]=nowy.wsk[k-1]+suma/10;
                    k--;
                }
                k=nowy.rozmiar-rozmiar+i-1;
            }
            if(nowy.wsk[0]==0)
            {
                nowy2.~duze();
                nowy2.rozmiar=nowy.rozmiar-1;
                nowy2.wsk=new char[nowy2.rozmiar];
                for(i=nowy2.rozmiar-1;i>=0;--i)
                {
                    nowy2.wsk[i]=nowy.wsk[i+1];
                }
                nowy.~duze();
                return nowy2;
            }
        }
        return nowy;
    }
};

//********OPERATORY WEJSCIA**********//
istream & operator>>(istream & in, duze & d)
{
    const int rozmiar=10;
    int mnoznik=0;
    int i=0;
    int j;
    char buff;

    duze d2;
    d2.wsk=new char[rozmiar*(mnoznik+1)];

    while((in.get(buff))&&(buff!='\n'))
    {
        if(i==rozmiar*mnoznik)
        {
            mnoznik++;
            if(mnoznik%2==1)
            {
                delete [] d.wsk;
                d.wsk=new char[rozmiar*mnoznik];
                d.rozmiar=rozmiar*mnoznik;
                for(j=0;j<rozmiar*(mnoznik-1);j++)
                {
                    d.wsk[j]=d2.wsk[j];
                }
            }
            else
            {
                delete [] d2.wsk;
                d2.wsk=new char[rozmiar*mnoznik];
                d2.rozmiar=rozmiar*mnoznik;
                d.rozmiar=rozmiar*mnoznik;
                for(j=0;j<rozmiar*(mnoznik-1);j++)
                {
                    d2.wsk[j]=d.wsk[j];
                }
            }
        }

        if(mnoznik%2==1)
            d.wsk[i]=buff-48;
        else
            d2.wsk[i]=buff-48;

        i++;
    }

    if(i!=mnoznik*rozmiar)
    {
        if(mnoznik%2==0)
        {
            delete [] d.wsk;
            d.wsk=new char[i];
            d.rozmiar=i;
            for(j=0;j<i;j++)
            {
                d.wsk[j]=d2.wsk[j];
            }
        }
        else
        {
            delete [] d2.wsk;
            d2.wsk=new char[i];
            d.rozmiar=i;
            for(j=0;j<i;j++)
            {
                d2.wsk[j]=d.wsk[j];
            }

            delete [] d.wsk;
            d.wsk=new char[i];
            for(j=0;j<i;j++)
            {
                d.wsk[j]=d2.wsk[j];
            }
        }
    }
    d2.~duze();

    /*const int rozmiar=10;
    int mnoznik=1;
    d.wsk=new char[rozmiar];
    int i=0;
    int j;
    d.rozmiar=rozmiar*mnoznik;

    while((in.get(d.wsk[i]))&&(d.wsk[i]!='\n'))
    {
        d.wsk[i]=d.wsk[i]-48;

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
            d.rozmiar=rozmiar*mnoznik;
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
    }*/

    return in;
}

//********OPERATORY WYJSCIA**********//
ostream & operator<<(ostream & out, duze & d)
{
    int i=0;
    while(i<d.rozmiar)//d.wsk[i]!='\0')//i<200)
    {
        out<<int(d.wsk[i]);
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
    //cout<<"D1: "<<endl<<d1<<endl;
    //cout<<"D2: "<<endl<<d2<<endl;

    //d3=d1+d2;
    d3=d1*d2;
    d3=d1*d2;
    cout<<endl<<"D1: "<<endl<<d1<<endl;
    cout<<endl<<"D2: "<<endl<<d2<<endl;
    cout<<endl<<"D3: "<<endl<<d3<<endl;



    return 0;
}
