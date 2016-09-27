#include <iostream>
using namespace std;

void mozliwosci ()
{
    int i=0;
    for(int a=1;a<=49;a++)
    {
        for(int b=1;b<=49;b++)
        {
            for(int c=1;c<=49;c++)
            {
                for(int d=1;d<=49;d++)
                {
                    for(int e=1;e<=49;e++)
                    {
                        for(int f=1;f<=49;f++)
                        {
                            if((a>=b)||(b>=c)||(c>=d)||(d>=e)||(e>=f))
                                continue;

                            //cout<<a<<", "<<b<<", "<<c<<", "<<d<<", "<<e<<", "<<f<<", "<<endl;
                            i++;

                        }
                    }
                }
            }
        }
    }
    cout<<i<<endl;
}

int main ()
{
    mozliwosci();
    return 0;
}
