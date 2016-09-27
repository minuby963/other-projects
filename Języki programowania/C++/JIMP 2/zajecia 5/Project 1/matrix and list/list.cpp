#include <iostream>
#include <stdio.h>
#include "headers.hpp"

using namespace std;

template <class wz>
class lista;

//****elementy listy****//
el::el()
{
    next=NULL;
}

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
lista::usun_el(lista<wz> &li)
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

lista::lista()
{
    pierwszy=NULL;
}

lista::~lista()
{
    usun_el(*this);
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

        while(this->pierwszy!=0)
        {
            tmp2=this->pierwszy->next;
            delete this->pierwszy;
            this->pierwszy=tmp2;
        }
        this->pierwszy=NULL;
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

        while(li.pierwszy!=NULL)
        {
            tmp=li.pierwszy->next;
            delete li.pierwszy;
            li.pierwszy=tmp;
        }
        li.pierwszy=NULL;

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
};
