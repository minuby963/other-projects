#include <stdio.h>
int main ()
{
    int liczba;
    int c;
    printf("podaj liczbe: ");
    scanf ("%d", &liczba);
    if (liczba>=2)
    {
        for(c=2;c<liczba;c++)
        {
            if (liczba%c==0)
            {
                printf("liczba nie jest pierwsza \n");
                c=liczba+1;
            }
        }
        if(c==liczba)
            printf("liczba jest pierwsza");
    }
    else
        printf("nie jest pierwsza");
    return 0;
}
