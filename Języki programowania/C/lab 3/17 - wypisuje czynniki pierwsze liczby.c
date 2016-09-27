#include <stdio.h>

int main()
{
    int liczba;
    int i=2;
    int licznik = 0;
    int reszta;
    printf("podaj liczbe: ");
    scanf("%d",&liczba);

    while (liczba>1)
    {
        while(liczba%i==0)
        {
            licznik++;
            liczba=liczba/i;
        }
        if (licznik != 0)
            printf("%d^%d\n",i,licznik);
        i++;
        licznik=0;
    }
    return 0;
}
