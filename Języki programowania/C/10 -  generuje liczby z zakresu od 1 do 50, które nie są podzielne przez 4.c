#include <stdio.h>
int main ()
{
    int a=1;
    for (;a<=40;a++)
    {
        if (a%4!=0)
            continue;
        printf("%d \n", a);
    }
    return 0;
}
