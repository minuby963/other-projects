#include <stdio.h>

int main()
{
    int a;
    int b;
    int i;
    printf("podaj zakres: ");
    scanf("%d\n%d",&a,&b);
    printf("\n");
    for(;a<=b;a++)
    {
        i=2;
        while (i<=a)
        {
            if(a%i == 0)
               break;
            i++;
        }
        if (a==i)
            printf("%d\n",a);
    }
    return 0;
}
