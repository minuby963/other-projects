#include <stdio.h>
int main ()
{
    int a;
    int b;
    printf ("podaj a: ");
    scanf ("%d",&a);
    printf ("podaj b: ");
    scanf ("%d", &b);
    printf ("suma: %d \n", a+b);
    printf ("roznica: %d \n", a-b);
    printf ("iloczyn: %d \n", a*b);
    printf ("iloraz: %d \n", a/b);
    printf ("reszta z dzielenia: %d \n", a%b);
    return 0;
}
