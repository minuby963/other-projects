#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int losowanie_liczby()
{
    srand(time(NULL));
    int a;
    int b;

    a=rand();
    b=rand();

    return (b%10)+51;
}
int main()
{
    int a;
    int b;
    cout<<losowanie_liczby()<<endl;
    a=losowanie_liczby();
    cout<<a<<endl;


    b=losowanie_liczby();
    cout<<b;



    return 0;
}
