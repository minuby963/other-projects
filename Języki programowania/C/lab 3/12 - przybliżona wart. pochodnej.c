#include <stdio.h>

int main ()
{
    double h;
    h=1.00;
    printf ("%f \n", h);
    int i;
    int x;
    double p_pochodnej;
    printf ("podaj pkt. w ktorym program ma policzyc pochodna z funkcji f: f(x) = x^2 \n");
    scanf("%d", &x);
    printf ("przybli¿ona wartosc pochodnej  funkcji f: f(x)=x^2 w pkt. %d wynosi: \n", x);

    for(i=0;i<10;i++)
    {
        //p_pochodnej = ((x+h)^2)/h;
        p_pochodnej = ((x+h)*(x+h) - x*x)/h;
        //system ("sleep 10");
        printf ("dla h = %f                f'(1) = %f \n",h,p_pochodnej);
        h=h/10;
    }
    return 0;
}
