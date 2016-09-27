#include <stdio.h>
int main ()
{
    int zakres;
    int i=1;
    printf ("podaj zakres");
    scanf("%d", &zakres);
    printf("\n");
    while (i<=zakres)
    {
        printf("nr. %d \n", i);
        i=i+1;
    }
    return 0;
}
