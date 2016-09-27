#include <iostream>
//#include "headers.hpp"

using namespace std;

class complex2
{
public:
    int real;
    int imaginary;


    complex2 & operator+(complex2 & com)
    {
        int i=0,j=0;
        static complex2 com3(i,j);
        com3.real=this->real+com.real;
        com3.imaginary=this->imaginary+com.imaginary;
        return com3;
    }
    complex2(int alfa, int beta)
    {
        real=alfa;
        imaginary=beta;
    }
};

ostream &operator<<(ostream &out, complex2 & com)
{
    out<<"z= "<<com.real<<"+i*"<<com.imaginary<<endl;
    return out;
}
int main()
{
    int a1=1,b1=1,a2=2,b2=2;
    complex2 com1(a1,a2);
    complex2 com2(b1,b2);
    complex2 com(b2,b2);
    cout<<com1;
    com=com1+com2;
    cout<<com;
    //cout<<<<com.real<<"+i*"<<com.imaginary<<endl;

    return 0;
}
