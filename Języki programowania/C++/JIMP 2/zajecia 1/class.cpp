#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

class czas {
    public:
    int h;
    int min;
    int sec;

     void wczytaj(int a, int b, int c)
     {
        h=a;
        min=b;
        sec=c;
     }

     void odczytaj(int &a, int &b, int &c)
     {
        a=h;
        b=min;
        c=sec;
     }

     void wczytaj(const char *tab)
     {
        sscanf(tab,"%d:%d:%d",&h,&min,&sec);
     }

     void odczytaj(char *tab)
     {
        sprintf(tab, "%d:%d:%d", h, min, sec);
     }
     czas(string miasto)
     {
         time_t czas = time(0);
         tm *t = localtime(&czas);

         if(miasto=="Warszawa")
         {
            h=t->tm_hour;
            min=t->tm_min;
            sec=t->tm_sec;
         }
         else
         {
             if(miasto=="Chicago")
             {
                h=t->tm_hour-7;
                if(h<0)
                {
                    h=h+24;
                }
                min=t->tm_min;
                sec=t->tm_sec;
             }
             else
             {
                 if(miasto=="Londyn")
                 {
                    h=t->tm_hour-1;
                    if(h<0)
                    {
                        h=h+24;
                    }
                    min=t->tm_min;
                    sec=t->tm_sec;
                 }
                 else
                 {
                    h=t->tm_hour-1;
                    min=t->tm_min;
                    sec=t->tm_sec;
                    cout<<"nie ma w bazie tego miasta"<<endl;
                 }
             }
         }
     }
};

int main ()
{
    int a,b,c;
    char tab [200];
    string miasto;
    cout<<"Podaj miasto: ";
    cin>>miasto;


    czas o1("Warszawa");


    czas k1(miasto);


    k1.odczytaj(a,b,c);

    cout<<a<<":"<<b<<":"<<c<<endl;

    a=11;
    b=22;
    c=33;
    o1.wczytaj(a,b,c);
    a++;
    b++;
    c++;
    o1.odczytaj(a,b,c);

    cout<<a<<":"<<b<<":"<<c<<endl;

    o1.wczytaj("10:20:30");
    o1.odczytaj(tab);
    cout<<a<<":"<<b<<":"<<c<<endl;

    return 0;
}
