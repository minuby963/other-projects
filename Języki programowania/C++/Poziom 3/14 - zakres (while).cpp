#include <iostream>
using namespace std;

void zakres( int x, int y )
{
   while (x<=y)
   {

       cout<<x<<", ";
       x++;
   }

   cout<<"koniec"<<endl;
}

int main()
{
    zakres( 1, 5 );
    zakres( 8, - 1 );
    zakres( 10, 10 );
    return 0;
}
