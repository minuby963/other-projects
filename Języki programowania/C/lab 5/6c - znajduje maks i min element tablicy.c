#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main ()
{
    float tab [100];
    srand (time(NULL));
    int a;
    a=rand ();
    //printf("%d",a);
    for (a=0;a<100;a++)
    {
        tab[a]=1.0 * rand() / (RAND_MAX - 1);
        printf("%f \n",tab[a]);
    }
    return 0;

}
