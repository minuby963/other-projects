#include <stdio.h>

int main ()
{
    int a,b;
    int c,d;
    int e;
    int zmiana;
    do
    {
        printf("podaj czy chcesz dowolna tabliczke (1) czy bez liczb pod przekatna 10x10 (0)\n");
        scanf("%d",&zmiana);
    }
    while (zmiana != 1 && zmiana != 0);

    if (zmiana ==1)
    {
        printf("poadaj zakres w poziomie (dol)\n");
        scanf("%d",&e);
        printf("poadaj zakres w poziomie (gora)\n");
        scanf("%d",&d);
        printf("poadaj zakres w pionie (dol)\n");
        scanf("%d",&a);
        printf("poadaj zakres w pionie (gora)\n");
        scanf("%d",&c);
    }
    else
    {
        c=d=10;
        a=e=1;
    }
    for (;a<=c;a++)
    {
        for (b=e;b<=d;b++)
        {
            if (zmiana == 0)
            {
                if(a<=b)
                    printf ("%4d",a*b);
                else
                    printf ("    ");
            }
            else
                printf ("%4d",a*b);
        }
        printf("\n");
    }
    return 0;
}
