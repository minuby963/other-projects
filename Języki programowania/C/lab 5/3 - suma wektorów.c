#include <stdio.h>

int main ()
{
    int wek1[5];
    int wek2[5];
    int i=0;
    printf("podaj wspolrzedne wektora nr 1\n");
    for(i=0;i<5;i++)
    {
        scanf("%d",&wek1[i]);
    }

    printf("podaj wspolrzedne wektora nr 2\n");
    for(i=0;i<5;i++)
    {
        scanf("%d",&wek2[i]);
    }
    printf("wspolrzedne sumy wektorow to: \n");
    for(i=0;i<5;i++)
    {
        printf("%d,",wek1[i]+wek2[i]);
    }
    return 0;
}

