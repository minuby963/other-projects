#include <iostream>
using namespace std;

int main ()
{
cout<<"instrukcja: "<<endl<<"1 - dodawanie"<<endl<<"2 - odejmowanie"<<endl<<"3 - mno¿enie"<<endl<<"4 - dzielenie"<<endl;

int a;
cout<<"podaj a"<<endl;
cin>>a;

int c;
cout<<"numer symbolizuj¹cy dzia³anie"<<endl;
cin>>c;

int b;
cout<<"podaj b"<<endl;
cin>>b;

switch(c)
{
case 1:
cout<<" = "<<a+b;
break;

case 2:
cout<<" = "<<a-b;
break;

case 3:
cout<<" = "<<a*b;
break;

case 4:
cout<<" = "<<a/b;
break;

default:
cout<<"coœ jest nie tak";
break;
}

return 0;
}
