#include <stdio.h>
int main ()
{
    int a;
    printf("podaj a\n");
    scanf("%d",&a);
    if (a>0)
        printf("wieksza od zera");
    else
    {
        if (a==0)
            printf("rowna zero");
        else
            printf("mniejsza od zera");
    }
    return 0;
}
