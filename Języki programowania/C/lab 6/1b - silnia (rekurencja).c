#include <stdio.h>

int silnia (int stopien)
{
    if (stopien<=1)
        return 1;
    return stopien * silnia (stopien-1);
}

int main ()
{
   int stopien;
   printf("podaj liczbe \n");
   scanf("%d",&stopien);
   printf("silnia = %d\n",silnia(stopien));
   return 0;
}
