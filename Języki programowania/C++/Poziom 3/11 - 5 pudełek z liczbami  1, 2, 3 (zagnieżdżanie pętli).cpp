#include <iostream>
using namespace std;

void wypisuj ()
{
    for (int a= 1; a<=3; a++)
    {
        for (int b= 1; b<=3; b++)
        {
            for (int c= 1; c<=3; c++)
            {
                for (int d= 1; d<=3; d++)
                {
                    for (int e= 1; e<=3; e++)
                    {
                        cout<<a<<b<<c<<d<<e<<endl;
                    }
                }
            }
        }

    }
}

int main ()
{
    wypisuj();
    return 0;
}
