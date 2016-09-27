#include <iostream>
using namespace std;

int newton(int n, int k)
{
    if((n==k)||(k==0))
    {
        return 1;
    }
    else
    {
        return newton(n-1,k-1)+newton(n-1,k);
    }
}

int main()
{

    int n, k;
    cin>>n;
    cin>>k;
    cout<<newton(n,k)<<endl;
    return 0;
}
