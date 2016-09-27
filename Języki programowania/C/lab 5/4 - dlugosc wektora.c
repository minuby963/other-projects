#include <stdio.h>
#include <math.h>

int main ()
{
    float v[7];
    int i=0;
    printf("podaj wspolrzedne (7)\n");
    for(i=0;i<7;i++)
        scanf("%f",&v[i]);
    printf("dlugosc = %f\n",sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]+v[3]*v[3]+v[4]*v[4]+v[5]*v[5]+v[6]*v[6]));
}
