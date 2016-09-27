#include <iostream>
#include <stdio.h>
#include "header.hpp"

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



istream &operator>>(istream & s, macierze & k1){
    int i=0;

    if(k1.wsk != NULL){
        delete [] k1.wsk;
    }
    s>>k1.rozmiar;
    k1.wsk=new int[k1.rozmiar*k1.rozmiar];

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
