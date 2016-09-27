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
};

    istream &operator>>(istream & s, macierze & k1){
        int i=0;

        if(k1.wsk != NULL){
            delete [] k1.wsk;
        }

        cout<<"rozmiar"<<endl;
        s>>k1.rozmiar;
        k1.wsk=new int[k1.rozmiar*k1.rozmiar];

        cout<<"dane"<<endl;
        for(i=0; i<k1.rozmiar*k1.rozmiar; i++){
            s>>k1.wsk[i];

        }
        return s;
    }




ostream &operator<<(ostream & s, macierze & k1){
    int i;
    int j;

    for(i=0;i<k1.rozmiar*k1.rozmiar;i++)
    {
        s<<k1.wsk[i]<<" ";
        if(((i+1) % k1.rozmiar)==0)
        {
            s<<endl;
        }
    }

    return s;
}





int main()
{

    macierze k1;

    macierze k2;
    k1=k2;
    cin>>k1;
    cin>>k2;

    cout<<"k1"<<endl<<k1<<endl;
    cout<<"k2"<<endl<<k2<<endl;
    k1=k2;

    cout<<"k1=k2"<<endl<<k1<<endl;
    cout<<"k2"<<endl<<k2<<endl;
    return 0;

}
