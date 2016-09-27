#ifndef HEADERS_HPP_INCLUDED
#define HEADERS_HPP_INCLUDED

template <class wz>
class lista;

template <class wz>
class el
{
    wz w1;
    el<wz> *next;

    el()
    {
         next=NULL;
    }
};





template <class wz>
class lista
{
public:
    el<wz> *pierwszy;

    lista();
};


#endif // HEADERS_HPP_INCLUDED
