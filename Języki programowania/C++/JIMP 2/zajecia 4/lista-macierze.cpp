#include <iostream>
using namespace std;

class macierze {
    public:
    int * wsk;
    int rozmiar;
    macierze(){

        wsk=NULL;
        rozmiar=0;
    }

    ~macierze(){
        if(wsk != NULL){
            delete [] wsk;
        }
    }

    macierze & operator=(macierze & k1){
        int i;
        if(this==&k1) return *this;
        /*if(wsk != NULL){
            delete [] wsk;
            wsk=new int[k1.rozmiar*k1.rozmiar];
        }*/
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
                    //tmp1.wsk[i*rozmiar+j]=tmp1.wsk[i*rozmiar+j]+this->wsk[k+j*rozmiar]*k1.wsk[j+k*rozmiar];
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
        else{
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
                if(s1<=s2){
                    return 1;
                }
                else{
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



istream &operator>>(istream & s, macierze & k1){
    int i=0;

    if(k1.wsk != NULL){
        delete [] k1.wsk;
    }
    //cout<<"rozmiar"<<endl;
    s>>k1.rozmiar;
    k1.wsk=new int[k1.rozmiar*k1.rozmiar];

    //cout<<"dane"<<endl;
    for(i=0; i<k1.rozmiar*k1.rozmiar; i++){
        s>>k1.wsk[i];
    }
    return s;
}

ostream &operator<<(ostream & s, macierze & k){
    int i;
    int j;

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

public:
    el()
    {
         //w1=0;
         next=NULL;
    }
};

template <class wz>
class lista
{
public:
    //friend istream & operator>>(istream & in,lista<wz> & l1);
    //friend ostream & operator<<(ostream & out,lista<wz> & l1);

    el<wz> *pierwszy;


//public:

    lista()
    {
        pierwszy=NULL;

    }
    ~lista()
    {
        el<wz> *tmp;
        el<wz> *tmp2;

        tmp=this->pierwszy;

        while(tmp!=NULL)
        {
            tmp2=tmp->next;
            delete tmp;
            tmp=tmp2;
        }
    }

    void sort()
    {
        if(pierwszy==NULL)
        {

        }
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

    lista &operator+(lista &l1)
    {
        lista<wz> *li;
        el<wz> *tmp;
        el<wz> *tmp2;
        el<wz> *elem;

        tmp=pierwszy;
        li=new lista<wz>;
        while(tmp!=NULL)
        {
            elem=new el<wz>;
            elem->w1=tmp->w1;
            if(tmp==pierwszy)
            {
                li->pierwszy=elem;
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
        return *li;
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
        out<<tmp->w1<<endl<<", "<<endl;
        tmp=tmp->next;
    }
    return out;
}

int main()
{
    macierze m1;
    macierze m2;
    lista<macierze> a;
    lista<macierze> b;
    lista<macierze> c;
    cout<<"pierwszy parametr to rozmiar macierzy"<<endl;
    cin>>a;
    cout<<"pierwszy parametr to rozmiar macierzy"<<endl;
    cin>>a;
    cout<<"pierwszy parametr to rozmiar macierzy"<<endl;
    cin>>a;
    cout<<"pierwszy parametr to rozmiar macierzy"<<endl;
    cin>>b;
    cout<<"pierwszy parametr to rozmiar macierzy"<<endl;
    cin>>b;
    cout<<endl<<"a: "<<endl<<a<<endl;
    cout<<"b: "<<endl<<b<<endl;
    a.sort();
    cout<<"sorted a: "<<endl<<a<<endl;
    c=a+b;
    cout<<endl<<"c: "<<endl<<c<<endl;

    /*c.~lista();
    cout<<"destruktor c: "<<a<<endl;*/
    return 0;
}
