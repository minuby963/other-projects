/*#include <iostream>
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
    out<<com.real<<"+i*"<<com.imaginary<<endl;
    return out;
}*/







