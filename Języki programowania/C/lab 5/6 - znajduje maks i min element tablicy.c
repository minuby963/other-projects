#include <stdio.h>

int main ()
{
    double tab [100];
    srand (time(NULL));
    int a;
    a=rand ();
    printf("%d",a);
    for (a=0;a<100;a++)
    {
        tab[a]=rand(10);
        printf("%f \n",tab[a]);
    }
    return 0;

}
