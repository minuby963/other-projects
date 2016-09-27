#include <iostream>

using namespace std;

int main ()
{
bool w;

int a;
cout<<"podaj a";
cin>>a;

int b;
cout<<"podaj b";
cin>>b;

w=(a<=b);
cout<<"w = "<<w<<endl;
cout<<!(true||w)<<endl;
cout<<((121>=b)&&(true&&w))<<endl;

return 0;

}
