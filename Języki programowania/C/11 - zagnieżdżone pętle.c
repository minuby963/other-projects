#include <stdio.h>
int main ()
{
    int i, j, a;
    for (i=0;i<=10;i++)
    {
        for (j=i;j<=i+10;j++)
        {
            a=(i+j)%21;
            printf("i=%d, j=%d, reszta z dzielenia przez 21=%d\n",i,j,a);
        }
    }
    return 0;
}
