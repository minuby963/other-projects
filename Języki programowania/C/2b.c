#include <stdio.h>
int main ()
{
    float a;
    float b;
    printf ("podaj a: ");
    scanf ("%f",&a);
    printf ("podaj b: ");
    scanf ("%f", &b);
    printf ("suma: %f \n", a+b);
    printf ("roznica: %f \n", a-b);
    printf ("iloczyn: %f \n", a*b);
    printf ("iloraz: %f \n", a/b);
    return 0;
}
