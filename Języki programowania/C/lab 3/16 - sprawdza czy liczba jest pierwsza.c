#include <stdio.h>

int main ()
{
    int liczba;
    int reszta;
    int i=2;
    printf("podaj liczbe: ");
    scanf("%d",&liczba);
    for(;i!=liczba;i++)
    {
        reszta =liczba%i;
        if (reszta == 0)
            break;
    }
    if (liczba == i)
        printf("liczba jest pierwsza");
    else
        printf("liczba nie jest pierwsza");
    return 0;
}
