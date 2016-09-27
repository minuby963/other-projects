#include <stdio.h>
int main()
{
    int liczba;
    printf("podaj liczbe: ");
    scanf ("%d", &liczba);
    if (liczba>0)
    {
        if(liczba%2==0)
            printf("dodatnia, parzysta");
        else
            printf("dodatnia, nieparzysta");
    }
    else
    {
        if (liczba==0)
            printf("liczba rowna zero");
        else
        {
            if(liczba%2==0)
                printf("ujemna, parzysta");
            else
                printf("ujemna, nieparzysta");
        }
    }
    return 0;
}
