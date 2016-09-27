#include <stdio.h>

int silnia (int stopien)
{
    int wynik;
    if (stopien>1)
    {
        wynik = wynik * silnia(stopien);
        stopien--;
    }
    return wynik;
}

int main ()
{
   int wynik=1;
   int stopien;
   printf("podaj liczbe \n");
   scanf("%d",&stopien);
   printf("silnia = %d\n",silnia(stopien));
   return 0;
}
