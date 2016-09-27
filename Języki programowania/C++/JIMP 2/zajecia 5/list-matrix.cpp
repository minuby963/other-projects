#include <iostream>
#include <stdio.h>
using namespace std;

class macierze
{
    public:
    int * wsk;
    int rozmiar;
    macierze()
    {
        wsk=NULL;
        rozmiar=0;
    }

    ~macierze()
    {
        if(wsk != NULL)
        {
            delete [] wsk;
        }
    }

    macierze & operator=(macierze & k1){
        int i;
        if(this==&k1) return *this;
        delete [] wsk;
        wsk=new int[k1.rozmiar*k1.rozmiar];
        rozmiar=k1.rozmiar;
        for(i=0; i<rozmiar*rozmiar; i++){

            this->wsk[i]=k1.wsk[i];
        }
        return *this;
    }

    macierze & operator+(macierze & k1)
    {
        if(k1.rozmiar!=this->rozmiar)
        {
            if(k1.rozmiar>rozmiar)
            {
                return k1;
            }
            else
            {
                return *this;
            }
        }
        int i;
        static macierze tmp1;
        delete [] tmp1.wsk;
        tmp1.wsk = new int[k1.rozmiar*k1.rozmiar];
        tmp1.rozmiar=k1.rozmiar;

        for(i=0; i<rozmiar*rozmiar; i++)
        {
            tmp1.wsk[i]=this->wsk[i]+k1.wsk[i];
        }
        return tmp1;
    }

    macierze & operator-(macierze & k1)
    {
        if(k1.rozmiar!=this->rozmiar)
        {
            if(k1.rozmiar<rozmiar)
            {
                return k1;
            }
            else
            {
                return *this;
            }
        }

        int i;
        static macierze tmp1;
        delete [] tmp1.wsk;
        tmp1.wsk = new int[k1.rozmiar*k1.rozmiar];
        tmp1.rozmiar=k1.rozmiar;
        for(i=0; i<rozmiar*rozmiar; i++)
        {
            tmp1.wsk[i]=this->wsk[i]-k1.wsk[i];
        }
        return tmp1;
    }

    macierze & operator*(macierze & k1)
    {
        if(k1.rozmiar!=this->rozmiar)
        {
            if(k1.rozmiar<rozmiar)
            {
                return k1;
            }
            else
            {
                return *this;
            }
        }
        int i, j, k=0;
        static macierze tmp1;
        delete [] tmp1.wsk;
        tmp1.wsk = new int[k1.rozmiar*k1.rozmiar];
        tmp1.rozmiar=k1.rozmiar;
        for(i=0; i<rozmiar; i++)
        {
            tmp1.wsk[i]=0;
        }
        for(i=0; i<rozmiar; i++)
        {
            for(j=0; j<rozmiar; j++)
            {
                for(k=0; k<rozmiar; k++)
                {
                    tmp1.wsk[i+rozmiar*j]=tmp1.wsk[i+rozmiar*j]+this->wsk[k+j*rozmiar]*k1.wsk[i+k*rozmiar];
                }
            }
        }
        return tmp1;
    }
    int operator==(macierze & k1)
    {
        int i, wynik=1;
        if(rozmiar!=k1.rozmiar)
        {
            wynik=0;
            return wynik;
        }
        for(i=0; i<rozmiar*rozmiar; i++)
        {
            if((this->wsk[i])!=(k1.wsk[i]))
            {
                wynik=0;
                return wynik;
            }
        }
        return wynik;
    }
    int operator!=(macierze & k1)
    {
        int i, wynik=0;
        if(rozmiar!=k1.rozmiar)
        {
            wynik=1;
            return wynik;
        }
        for(i=0; i<rozmiar*rozmiar; i++)
        {
            if((this->wsk[i])!=(k1.wsk[i]))
            {
                wynik=1;
                return wynik;
            }
        }
        return wynik;
    }
    int operator<=(macierze & k1)
    {
        int i;
        int s1=0, s2=0;
        if(rozmiar>k1.rozmiar)
        {
            return 0;
        }
        else
        {
            if(rozmiar<k1.rozmiar)
            {
                return 1;
            }
            else{
                for(i=0;i<rozmiar*rozmiar;i++)
                {
                    s2=s2+k1.wsk[i];
                    s1=s1+this->wsk[i];
                }
                if(s1<=s2)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    int operator>=(macierze & k1)
    {
        int i;
        int s1=0, s2=0;
        if(rozmiar<k1.rozmiar)
        {
            return 0;
        }
        else{
            if(rozmiar>k1.rozmiar)
            {
                return 1;
            }
            else{
                for(i=0;i<rozmiar*rozmiar;i++)
                {
                    s2=s2+k1.wsk[i];
                    s1=s1+this->wsk[i];
                }
                if(s1>=s2)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    int operator>(macierze & k1)
    {
        int i;
        int s1=0, s2=0;
        if(rozmiar>k1.rozmiar)
        {
            return 1;
        }
        else{
            if(rozmiar<k1.rozmiar)
            {
                return 0;
            }
            else{
                for(i=0;i<rozmiar*rozmiar;i++)
                {
                    s2=s2+k1.wsk[i];
                    s1=s1+this->wsk[i];
                }
                if(s1>s2)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    int operator<(macierze & k1)
    {
        int i;
        int s1=0, s2=0;
        if(rozmiar<k1.rozmiar)
        {
            return 1;
        }
        else{
            if(rozmiar>k1.rozmiar)
            {
                return 0;
            }
            else{
                for(i=0;i<rozmiar*rozmiar;i++)
                {
                    s2=s2+k1.wsk[i];
                    s1=s1+this->wsk[i];
                }
                if(s1<s2)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    macierze(const macierze& k)
    {
        int i;
        rozmiar=k.rozmiar;
        wsk= new int[rozmiar*rozmiar];

        for(i=0;i<rozmiar*rozmiar;i++)
        {
            wsk[i]=k.wsk[i];
        }
    }
};

istream &operator>>(istream & s, macierze & k1)
{
    int i=0;

    if(k1.wsk != NULL)
    {
        delete [] k1.wsk;
    }
    s>>k1.rozmiar;
    k1.wsk=new int[k1.rozmiar*k1.rozmiar];

    for(i=0; i<k1.rozmiar*k1.rozmiar; i++)
    {
        s>>k1.wsk[i];
    }
    return s;
}

ostream &operator<<(ostream & s, macierze & k)
{
    int i;

    for(i=0;i<k.rozmiar*k.rozmiar;i++)
    {
        s<<k.wsk[i]<<" ";
        if(((i+1) % k.rozmiar)==0)
        {
            s<<endl;
        }
    }
    return s;
}

template <class wz>
class lista;

template <class wz>
class el
{
    friend istream & operator>>(istream & in,lista<wz> & l1);
    friend ostream & operator<<(ostream & out,lista<wz> & l1);
    friend class lista<wz>;
public:
    wz w1;
    el<wz> *next;

    el()
    {
         next=NULL;
    }
};

template <class wz>
istream & operator>>(istream & in,lista<wz> & l1)
{
    el<wz> *e1;
    e1 = new el<wz>;
    in>>e1->w1;
    e1->next=NULL;

    if(l1.pierwszy==NULL)
    {
        l1.pierwszy=e1;
    }
    else
    {
        el<wz> *tmp;
        tmp=l1.pierwszy;
        while(tmp->next!=NULL)
        {
            tmp=tmp->next;
        }
        tmp->next=e1;
    }
    return in;
}

template <class wz>
ostream & operator<<(ostream & out,lista<wz> & l1)
{
    el<wz> *tmp;
    tmp=l1.pierwszy;
    while(tmp!=NULL)
    {
        out<<tmp->w1<<endl;
        tmp=tmp->next;
    }
    return out;
}

template <class wz>
class lista
{
public:
    el<wz> *pierwszy;

    lista()
    {
        pierwszy=NULL;

    }
    ~lista()
    {
        el<wz> *tmp2;

        while(this->pierwszy!=NULL)
        {
            tmp2=this->pierwszy->next;
            delete this->pierwszy;
            this->pierwszy=tmp2;
        }
        this->pierwszy=NULL;
    }

    void sort()
    {
        if(pierwszy==NULL);
        else
        {
            el<wz> *tmp1;
            el<wz> *tmp2;
            wz tmpwz;
            tmp1=pierwszy;
            while(tmp1->next!=NULL)
            {
                tmp2=tmp1;
                while(tmp2->next!=NULL)
                {
                    tmp2=tmp2->next;
                    if((tmp1->w1)>(tmp2->w1))
                    {
                        tmpwz=tmp1->w1;
                        tmp1->w1=tmp2->w1;
                        tmp2->w1=tmpwz;
                    }
                }
                tmp1=tmp1->next;
            }
        }
    }

    lista<wz> &operator=(lista<wz> &l)
    {
        if(&l==this)
        {
            return *this;
        }
        el<wz> *tmp;
        el<wz> *tmp2;
        el<wz> *elem;

        this->~lista();
        /*
        while(this->pierwszy!=0)
        {
            tmp2=this->pierwszy->next;
            delete this->pierwszy;
            this->pierwszy=tmp2;
        }
        this->pierwszy=NULL;
        */

        tmp=l.pierwszy;
        while(tmp!=NULL)
        {
            elem=new el<wz>;
            elem->w1=tmp->w1;
            if(tmp==l.pierwszy)
            {
                this->pierwszy=elem;
                tmp2=elem;
            }
            else
            {
                tmp2->next=elem;
                tmp2=elem;
            }
            tmp=tmp->next;
        }
        return *this;
    }

    lista &operator+(lista &l1)
    {
        static lista<wz> li;
        el<wz> *tmp, *tmp2, *tmp3;
        el<wz> *elem;

        li.~lista();
        /*
        while(li.pierwszy!=NULL)
        {
            tmp=li.pierwszy->next;
            delete li.pierwszy;
            li.pierwszy=tmp;
        }
        li.pierwszy=NULL;
        */
        if(this->pierwszy==NULL)
        {
            li=l1;
            return li;
        }
        if(l1.pierwszy==NULL)
        {
            li=*this;
            return li;
        }
        else
        {
            li=*this;
            tmp=li.pierwszy;
            while(tmp->next!=NULL)
            {
                tmp=tmp->next;
            }

            tmp2=l1.pierwszy;
            while(tmp2!=NULL)
            {
                elem=new el<wz>;
                elem->w1=tmp2->w1;
                if(tmp2==l1.pierwszy)
                {
                    tmp->next=elem;
                    tmp3=elem;
                }
                else
                {
                    tmp3->next=elem;
                    tmp3=elem;
                }
                tmp2=tmp2->next;
            }
            return li;
        }
    }

    /*lista &operator+(lista &l1)
    {
        static lista<wz> li;
        el<wz> *tmp;
        el<wz> *tmp2;
        el<wz> *elem;

        while(li.pierwszy!=NULL)
        {
            tmp=li.pierwszy->next;
            delete li.pierwszy;
            li.pierwszy=tmp;
        }
        li.pierwszy=NULL;

        if(pierwszy!=NULL)
        {
            tmp=pierwszy;
            while(tmp!=NULL)
            {
                elem=new el<wz>;
                elem->w1=tmp->w1;
                if(tmp==pierwszy)
                {
                    li.pierwszy=elem;
                    tmp2=elem;
                }
                else
                {
                    tmp2->next=elem;
                    tmp2=elem;
                }
                tmp=tmp->next;
            }

            tmp=l1.pierwszy;
            while(tmp!=NULL)
            {
                elem=new el<wz>;
                elem->w1=tmp->w1;
                tmp2->next=elem;
                tmp2=elem;
                tmp=tmp->next;
            }
            return li;
        }
        else
        {
            tmp=l1.pierwszy;
            while(tmp!=NULL)
            {
                elem=new el<wz>;
                elem->w1=tmp->w1;
                if(tmp==l1.pierwszy)
                {
                    li.pierwszy=elem;
                    tmp2=elem;
                }
                else
                {
                    tmp2->next=elem;
                    tmp2=elem;
                }
                tmp=tmp->next;
            }
            return li;
        }
    }*/
};


int main()
{
    macierze m1;
    macierze m2;
    lista<macierze> a;
    lista<macierze> b;
    lista<macierze> c;
    lista<macierze> d;
    cout<<"lista a: pierwszy parametr to rozmiar macierzy"<<endl;
    cin>>a;
    cout<<"lista a: pierwszy parametr to rozmiar macierzy"<<endl;
    cin>>a;
    cout<<"lista a: pierwszy parametr to rozmiar macierzy"<<endl;
    cin>>a;

    cout<<"lista b: pierwszy parametr to rozmiar macierzy"<<endl;
    cin>>b;
    cout<<"lista b: pierwszy parametr to rozmiar macierzy"<<endl;
    cin>>b;

    /*cout<<endl<<"a: "<<endl<<a<<endl;
    cout<<"b: "<<endl<<b<<endl;
    cout<<"c: "<<endl<<c<<endl;*/

    //a=b;
    c=a+b;
    c=a+b;
    cout<<endl<<"////////// A: //////////"<<endl<<endl<<a<<endl;
    cout<<"////////// B: //////////"<<endl<<endl<<b<<endl;
    cout<<"////////// C: //////////"<<endl<<endl<<c<<endl;
    //cout<<"////////// D: //////////"<<endl<<endl<<d<<endl;
    c.sort();
    cout<<"////////// sorted C: //////////"<<endl<<endl<<c<<endl;

    //fflush(stdout);

    /*
    c.~lista();
    cout<<"destruktor c: "<<a<<endl;
    */

    return 0;
}
