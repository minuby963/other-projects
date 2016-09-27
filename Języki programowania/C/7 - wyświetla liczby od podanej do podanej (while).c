#include <stdio.h>
int main ()
{
    int poczatek;
    int koniec;
    int i=1;
    printf("podaj poczatek: ");
    scanf("%d", &poczatek);
    printf ("podaj koniec: ");
    scanf("%d", &koniec);
    while(poczatek<=koniec)
    {
        printf ("no.%d liczba: %d \n", i, poczatek);
        //printf("liczba: %d \n", poczatek);
        poczatek++;
        i++;
    }
    return 0;
}
