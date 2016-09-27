#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

class Zwierze{
public:
    virtual ~Zwierze(){};
};
class Kot : public Zwierze{};
class Pies : public Zwierze{};
class Kura : public Zwierze{};

class Zagroda{
public:
    int rozmiar;
    Zwierze **kontener;


    Zagroda(int r): rozmiar(r){
        kontener = new Zwierze* [rozmiar];
    }

    ~Zagroda(){
        delete [] kontener;
        rozmiar=0;
        kontener=NULL;
    }

    Zagroda(Zagroda& zag){
        if(!(zag.kontener==NULL || zag.rozmiar<=0)){
            rozmiar=zag.rozmiar;
            kontener= new Zwierze*[rozmiar];

            for(int i=0;i<rozmiar;++i){
                kontener[i]=new Zwierze(*(zag.kontener[i]));
            }
        }
    }
    Zagroda & operator=(Zagroda & zag){
        if(this == &zag)
            return *this;

        this->~Zagroda();
        rozmiar=zag.rozmiar;
        kontener= new Zwierze*[rozmiar];

        for(int i=0; i<rozmiar;++i){
            kontener[i]=new Zwierze(*(zag.kontener[i]));
        }
        return *this;
    }
};


int main()
{
    Kot *kot1;
    Zagroda zag(1);
    zag.kontener[0]=kot1;
    return 0;
}
