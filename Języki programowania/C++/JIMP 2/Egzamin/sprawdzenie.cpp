#include <iostream>
#include <stdio.h>
using namespace std;

class A
{
public:
    virtual void f(){
        printf("A.f ");
    }
    ~A(){f();}

};

class B
{
    A a;
public:
    void f(){
        printf("B.f ");
    }
    B(int i=0){
        if(!i)throw 0;
        printf("%d ",i);
    }
    ~B(){f();}
};

B b(12);

int main()
{
    try{
        cout<<"asfdsd"<<endl;
        A a;
        cout<<"2"<<endl;
        B *b = new B();
        cout<<"3"<<endl;
        delete b;

    }catch(int e){
        printf("--|| %d ||--Exc ", e);
    }
    return 0;
}
