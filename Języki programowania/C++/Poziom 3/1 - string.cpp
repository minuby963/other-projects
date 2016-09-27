#include <string>
#include <iostream>
using namespace std;

int main ()
{
    string a;
    string b;
    int i;
    for(i=0;i<10;i++)
    {
        cout<<"podaj wyraz"<<endl;
        cin>>a;
        b=a+", "+b;
    }
    cout<<b;

    return 0;
}
