#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

class polaczenie{
public:
    string nazw_wyj;
    string nazw_doc;
    polaczenie(string _nazw_wyj, string _nazw_doc){
        if(_nazw_doc!=_nazw_wyj){

            nazw_wyj=_nazw_wyj;
            nazw_doc=_nazw_doc;
            cout<<"nw: "<<nazw_wyj<<"; nd: "<<nazw_doc<<endl;
        }
    }
};

class SP{
public:
    vector <string> nazwiska;
    vector <polaczenie> pol;

    void dodaj (string v){
        for(vector<string>::iterator it=nazwiska.begin();it!=nazwiska.end();++it){
            if(v == *it)
                return;
        }
        nazwiska.push_back(v);
    }

    void usun (string v){
        for(vector<polaczenie>::iterator it=pol.begin() ;it<pol.end();it++){
            if(it->nazw_doc== v){
                    cout<<"ooo1"<<endl;
                pol.erase(it);
                cout<<"ooo"<<endl;
            }
        }
        for(vector<string>::iterator it=nazwiska.begin();it!=nazwiska.end();it++){
            if(v == *it){
                    cout<<"ooo2"<<endl;
                nazwiska.erase(it);
            }
        }



    }

    void dodajKrawedz(string os1,string os2){
        int i=0;
        for(vector<polaczenie>::iterator it=pol.begin();it<pol.end();it++){
            if((it->nazw_wyj== os1) && (it->nazw_doc==os2)){
                cout<<"a"<<endl;
                return;
            }
        }
        bool spr=false;
        for(vector<string>::iterator it=nazwiska.begin();it!=nazwiska.end();++it){
            if(os1 == *it){
                spr=true;
                break;
            }
        }
        if(spr==true){
            spr=false;
            for(vector<string>::iterator it=nazwiska.begin();it!=nazwiska.end();++it){
                if(os2 == *it){
                    spr=true;
                }
            }
        }
        if(spr==false) return;
        cout<<"dodaje"<<endl;
        polaczenie p(os1,os2);

        pol.push_back(p);
    }
    void scal(string os1, string os2){
        if(!binary_search(nazwiska.begin(),nazwiska.begin(),os1)) return;
        if(!binary_search(nazwiska.begin(),nazwiska.begin(),os2)) return;

    }

};

int main()
{
    SP sp;
    int i=0;

    string a="1", b="1";
    while(a!="0")
    {
        cout<<"dodaj nazwisko: "<<endl;
        cin>>a;
        //scanf("%s",&a);
        //fgets(a,256,stdin);
        sp.dodaj(a);
    }
    //sp.usun("0");
    cout<<endl<<"------------- NAZWISKA --------------"<<endl;
    for(vector<string>::iterator it=sp.nazwiska.begin();it!=sp.nazwiska.end();++it,i++){
        //cout<<sp.nazwiska.at(i)<<endl;
        cout<<*it<<endl;
    }
    while(b!="0")
    {
        cout<<"podaj os1:"<<endl;
        cin>>a;
        cout<<"podaj os2:"<<endl;
        cin>>b;
        //scanf("%s",&a);
        //fgets(a,256,stdin);
        sp.dodajKrawedz(a,b);
        //cout<<sp.pol[i].nazw_wyj<<"->"<<sp.pol[i].nazw_doc<<endl;
        i++;
    }

    cout<<endl<<"------------- POLACZENIA --------------"<<endl;
    for(vector<polaczenie>::iterator it=sp.pol.begin();it<sp.pol.end();it++,i++){
        cout<<it->nazw_wyj<<" -> "<<it->nazw_doc<<endl;
    }


    return 0;
}
