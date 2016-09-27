#include <iostream>
#include <fstream>
using namespace std;

class duze
{
public:
    char *wsk;
    int rozmiar;
public:

//********KONSTRUKTOR BEZARGUMENTOWY**********//
    duze()
    {
        wsk=NULL;
        rozmiar=0;
    }
//********KONSTRUKTOR ARGUMENTOWY**********//
    duze(int arg)
    {
        int licznik=1;
        int i=0;
        int tmp;
        if(arg==0)
        {
            wsk= new char[1];
            rozmiar=1;
            wsk[0]=0;
        }
        else
        {
            while(((arg/(licznik)))>0)
            {
                licznik=licznik*10;
                i++;
            }
            wsk= new char[i];
            rozmiar=i;
            tmp=i;
            for(;i>0;--i)
            {
                licznik=licznik/10;
                wsk[tmp-i]=arg/licznik;
                arg=arg%licznik;
            }
        }
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

//********OPERATOR>**********//
    int operator>(duze & d)
    {
        int j;
        if(this->rozmiar>d.rozmiar)
            return 1;
        if(this->rozmiar<d.rozmiar)
            return 0;
        else
        {
            for(j=0;j<rozmiar;j++)
            {
                if(wsk[j]>d.wsk[j])
                    return 1;
                if(wsk[j]<d.wsk[j])
                    return 0;
            }
            return 0;
        }
    }
//********OPERATOR>=**********//
    int operator>=(duze & d)
    {
        int j;
        if(this->rozmiar>d.rozmiar)
            return 1;
        if(this->rozmiar<d.rozmiar)
            return 0;
        else
        {
            for(j=0;j<rozmiar;j++)
            {
                if(wsk[j]>d.wsk[j])
                    return 1;
                if(wsk[j]<d.wsk[j])
                    return 0;
            }
            return 1;
        }
    }

//********OPERATOR==**********//
    int operator==(duze & d)
    {
        int j;
        if(this->rozmiar>d.rozmiar)
            return 0;
        if(this->rozmiar<d.rozmiar)
            return 0;
        else
        {
            for(j=0;j<rozmiar;j++)
            {
                if(wsk[j]>d.wsk[j])
                    return 0;
                if(wsk[j]<d.wsk[j])
                    return 0;
            }
            return 1;
        }
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
                        static duze nowy2
                        if(nowy2.wsk!=NULL)
                        {
                            nowy2.~duze();
                        }
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

//********OPERATOR-**********//
    duze & operator-(duze & d)
    {
        int i, j;
        int p, k;
        int tmp1, tmp2, tmp3;
        int roznica, reszta=0;
        static duze nowy;
        static duze nowy2;

        if(nowy.wsk!=NULL)
        {
            nowy.~duze();
        }
        if(d==*this)
        {
            nowy.wsk=new char[1];
            nowy.rozmiar=1;
            nowy.wsk[0]=0;
            return nowy;
        }
        nowy.rozmiar=((rozmiar > d.rozmiar) ? rozmiar : d.rozmiar);
        nowy.wsk=new char[nowy.rozmiar];

        for(i=0;i<nowy.rozmiar;i++)
            nowy.wsk[i]=0;

        if(rozmiar==0)
        {
            nowy=d;
            nowy.wsk[0]=-nowy.wsk[0];
            return nowy;
        }
        if(d.rozmiar==0)
        {
            nowy=*this;
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

                if(*this>d)
                {
                    roznica=tmp1-tmp2;
                }
                else
                {
                    roznica=tmp2-tmp1;
                }


                if(roznica>=0)
                {
                    nowy.wsk[j]=nowy.wsk[j]+roznica;
                }
                else
                {
                    nowy.wsk[j]=nowy.wsk[j]+roznica+10;
                    nowy.wsk[j-1]--;
                }
                if(nowy.wsk[j]<0)
                {
                    nowy.wsk[j]=9;
                    nowy.wsk[j-1]--;
                }
                j--;
            }
        }
        i=0;
        while(nowy.wsk[i]==0)
        {
            i++;
        }
        if(i>0)
        {
            if(nowy2.wsk!=NULL)
            {
                nowy2.~duze();
            }
            nowy2.rozmiar=nowy.rozmiar-i;
            nowy2.wsk=new char[nowy2.rozmiar];

            for(j=0;j<nowy2.rozmiar;j++)
            {
                nowy2.wsk[j]=nowy.wsk[i];
                i++;
            }
            nowy.~duze();
            if(d>*this)
            {
                nowy2.wsk[0]=-nowy2.wsk[0];
            }
            return nowy2;
        }

        if(d>*this)
        {
            nowy.wsk[0]=-nowy.wsk[0];
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
                if(nowy2.wsk!=NULL)
                {
                    nowy2.~duze();
                }
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

class duze2
    : public duze
{
public:
//********KONSTRUKTOR BEZARGUMENTOWY**********//
    duze2()
        //:duze()
    {
        wsk=NULL;
        rozmiar=0;
    }

//********KONSTRUKTOR ARGUMENTOWY**********//
    duze2(int arg)
        //:duze(arg)
    {
        int licznik=1;
        int i=0;
        int tmp;
        if(arg==0)
        {
            wsk= new char[1];
            rozmiar=1;
            wsk[0]=0;
        }
        else
        {
            while(((arg/(licznik)))>0)
            {
                licznik=licznik*10;
                i++;
            }
            wsk= new char[i];
            rozmiar=i;
            tmp=i;
            for(;i>0;--i)
            {
                licznik=licznik/10;
                wsk[tmp-i]=arg/licznik;
                arg=arg%licznik;
            }
        }
    }
//********DESTRUKTOR**********//
    ~duze2()
    {
        delete [] wsk;
        wsk=NULL;
    }

//********OPERATOR /**********//
    duze operator/(duze2 & d)
    {
        int i, j;
        int pocz_rozm;
        duze2 jeden(1);
        duze tmp1, tmp2;
        static duze tmp;
        duze tmp3(1);

        if(tmp.wsk!=NULL)
        {
            delete [] wsk;
        }
        if(d>*this)
        {
            tmp.wsk = new char[1];
            tmp.rozmiar=1;
            tmp.wsk[0]=0;
            return tmp;
        }
        tmp1.wsk = new char[d.rozmiar];
        tmp1.rozmiar=d.rozmiar;
        for(i=0;i<tmp1.rozmiar;i++)
        {
            tmp1.wsk[i]=this->wsk[i];
        }
        if(d>tmp1)
        {
            delete [] tmp1.wsk;
            tmp1.wsk = new char[d.rozmiar+1];
            tmp1.rozmiar=d.rozmiar+1;
            for(i=0;i<tmp1.rozmiar;i++)
            {
                tmp1.wsk[i]=this->wsk[i];
            }
        }
        tmp.wsk = new char[rozmiar+1-tmp1.rozmiar];
        tmp.rozmiar=rozmiar+1-tmp1.rozmiar;
        for(i=0;i<(rozmiar+1-tmp1.rozmiar);++i)
        {
            tmp.wsk[i]=0;
        }

        if(d>=jeden)
        {
            if(d==jeden)
            {
                tmp=*this;
            }
            else
            {
                pocz_rozm=tmp1.rozmiar;
                for(j=0;j<tmp.rozmiar;j++)
                {
                    /*cout<<endl<<"tmp1: ";
                    for(i=0;i<tmp1.rozmiar;i++)
                    {
                        cout<<int(tmp1.wsk[i]);
                    }*/
                    while(tmp1>=(d*tmp3))
                    {
                        tmp3=tmp3+jeden;
                    }
                    tmp3=tmp3-jeden;
                    //cout<<endl<<"tmp3: "<<int(tmp3.wsk[0])<<endl;

                    tmp.wsk[j]=tmp3.wsk[0];
                    if(tmp3.wsk[0]!=0)
                    {

                        tmp2=tmp1-d*tmp3;
                        if(tmp2.wsk[0]==0)
                        {
                            delete [] tmp2.wsk;
                            tmp2.rozmiar=0;
                        }
                    }
                    else
                    {
                        tmp2=tmp1;
                    }
                    /*cout<<"tmp2: ";
                    for(i=0;i<tmp2.rozmiar;i++)
                    {
                        cout<<int(tmp2.wsk[i]);
                    }*/

                    delete [] tmp1.wsk;
                    tmp1.wsk = new char[tmp2.rozmiar+1];
                    tmp1.rozmiar=tmp2.rozmiar+1;

                    i=0;
                    while(i<tmp2.rozmiar)
                    {
                        tmp1.wsk[i]=tmp2.wsk[i];
                        ++i;
                    }
                    tmp1.wsk[i]=this->wsk[j+pocz_rozm];
                    tmp3=jeden;
                    /*cout<<endl<<"tmp: ";
                    for(i=0;i<tmp.rozmiar;i++)
                    {
                        cout<<int(tmp.wsk[i]);
                    }*/
                }
            }
        }
        else
        {
            cout<<"dzielenie przez zero!"<<endl;
        }

        tmp1.~duze();
        tmp2.~duze();
        tmp3.~duze();
        jeden.~duze2();

        return tmp;
    }

//********OPERATOR %**********//
    duze operator%(duze2 & d)
    {
        static duze tmp;

        if(tmp.wsk!=NULL)
        {
            delete [] wsk;
        }
        tmp=*this-d*(*this/d);
        return tmp;
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

    delete [] d.wsk;
    d.wsk=NULL;

    duze d2;
    d2.wsk=new char[rozmiar*(mnoznik+1)];

    while(in.get(buff))
    {
        if((buff=='\n')&&(i==0))
        {
            d.wsk=new char[1];
            d.wsk[0]=0;
            d.rozmiar=1;
            return in;
        }
        if(buff!='\n')
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
        else
        {
            break;
        }
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

        }
    }
    if(mnoznik%2==1)
    {
        d2.~duze();
    }
    else
    {
        delete [] d.wsk;
        //d.wsk=d2.wsk;
        d.wsk=new char[i];
        for(j=0;j<i;j++)
        {
            d.wsk[j]=d2.wsk[j];
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
        out<<int(d.wsk[i]);
        i++;
    }
    return out;
}

int main()
{
    duze d1, d3;
    /*cout<<"Podaj 1 liczbe: "<<endl;
    cin>>d1;
    duze d2(d1);
    cout<<"Podaj 2 liczbe: "<<endl;
    cin>>d2;

    d3=d1-d2;
    //d3=d1*d2;
    cout<<endl<<"D1: "<<endl<<d1<<endl;
    cout<<endl<<"D2: "<<endl<<d2<<endl;
    cout<<endl<<"D3: "<<endl<<d3<<endl;*/

    duze2 du1, du3;
    cout<<"Podaj 1 liczbe: "<<endl;
    cin>>du1;
    duze2 du2(1);
    duze2 du4(1);
    cout<<"Podaj 2 liczbe: "<<endl;
    cin>>du2;
    d3=du1/du2;
    //cout<<"rozm: "<<d3.rozmiar<<endl;
    //cout<<"wart: "<<int(d3.wsk[0])<<endl;
    //cout<<"i: "<<du1/du2<<endl;
    cout<<endl<<"DUZE2 1: "<<endl<<du1<<endl;
    cout<<endl<<"DUZE2 2: "<<endl<<du2<<endl;
    cout<<endl<<"DUZE2 3: "<<endl<<d3<<endl;
    //cout<<endl<<"DUZE2 4: "<<endl<<du4<<endl;


    return 0;
}
