#include <stdio.h>

int main ()
{
    int liczba=14;
    int i;
    int reszta;
    char a = 'I';
    char b = 'V';
    char c = 'X';
    while (liczba<1||liczba>13)
    {
        printf("podaj liczbe od 1-13\n");
        scanf("%d",&liczba);
    }
    reszta = (liczba+1)%5-1;
    if(liczba==4 || liczba ==9)
        reszta=1;
    if(liczba>9)
        printf("X");
    if((liczba>4)&&(liczba<9))
        printf("V");

    while (reszta>0)
    {
        printf("%c",a);
        reszta--;
    }
    if (liczba==4)
        printf("V");
    if (liczba==9)
        printf("X");
    return 0;
}
