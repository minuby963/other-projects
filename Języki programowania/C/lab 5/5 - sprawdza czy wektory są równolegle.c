#include <stdio.h>

int main ()
{
    int i;
    float v1[7];
    float v2[7];
    printf("podaj wspolrzedne wektora nr 1 (7)\n");
    for(i=0;i<7;i++)
    {
        scanf("%d",&v1[i]);
    }
    printf("podaj wspolrzedne wektora nr 2 (7)\n");
    for(i=0;i<7;i++)
    {
        scanf("%d",&v2[i]);
    }
    for(i=1;i<7;i++)
    {
        if (v1[0]/v2[0] < v1[i]/v2[i] - 0.000001 || v1[0]/v2[0] > v1[i]/v2[i] + 0.000001)
        {
            printf("nierownolegle\n");
            break;
        }
    }
    if (i==6)
    {
        printf("rownolegle\n");
    }
    return 0;
}
