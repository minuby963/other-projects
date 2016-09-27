#include <stdio.h>
int main ()
{
    int liczba = 1;
    while (liczba<=10)
    {
        printf("%d^2 = %d \n", liczba, liczba*liczba);
        liczba++;
    }
    return 0;
}
