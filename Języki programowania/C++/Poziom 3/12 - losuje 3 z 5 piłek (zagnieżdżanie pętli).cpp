#include <iostream>
using namespace std;

void wypisz ()
{
    for(int a=1;a<=5;a++)
    {
        for(int b=1;b<=5;b++)
        {
            for(int c = 1; c<=5; c++)
            {
                if((a>=b)||(b>=c))
                continue;
                cout<<a<<b<<c<<endl;
            }
        }
    }
}

int main ()
{
    wypisz();



    return 0;
}
