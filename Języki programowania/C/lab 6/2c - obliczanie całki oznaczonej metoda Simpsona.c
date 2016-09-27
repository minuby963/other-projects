#include <stdio.h>
int a=0;
double simps (double lewy, double prawy, double delta)
{
    double wynik;
    printf("lewy = %f   i prawy = %f \n", lewy, prawy);
    double c=(prawy+lewy)/2;
    //printf("c = %f\n",c);
    double h=prawy-lewy;
    double fa=lewy*lewy*lewy*lewy;
    double fb=prawy*prawy*prawy*prawy;
    double fab=(lewy/2+prawy/2)*(lewy/2+prawy/2)*(lewy/2+prawy/2)*(lewy/2+prawy/2);
    wynik =h*(fa+4*fab+fb)/6;
    //printf("wynik = %f\n",wynik);
    return wynik;
}
double polowienie (double lewy, double prawy, double delta)
{
    double wynik;
    double P,P1,P2;
    a++;
    P = simps(lewy, prawy, delta);
    //printf("P = %f\n",P);
    P1 = simps(lewy, (lewy+prawy)/2, delta);
    //printf("P1 = %f\n",P1);
    P2 = simps((lewy+prawy)/2,prawy, delta);
    //printf("P2 = %f\n",P2);
    //printf("P1+P2 = %f\n",P1+P2);
    if((P-delta<P1+P2)&&(P+delta>P1+P2))
        return P1+P2;
    else
        return polowienie (lewy,(prawy+lewy)/2, delta/2)+ polowienie ((prawy+lewy)/2, prawy, delta/2);
}

int main()
{
    printf("oblicza pole pod f(x) = x^4 w zadanym przedziale \n");
    //double lewy = -2;
    //double prawy = 6;
    //double delta = 0.0000001;
    double lewy;
    double prawy;
    double delta;
    printf("\npodaj poczatek przedzialu: ");
    scanf("%lf",&lewy);
    printf("\npodaj koniec przedzialu:   ");
    scanf("%lf",&prawy);
    printf("\npodaj dokladnosc:          ");
    scanf("%lf",&delta);
    printf("wynik = %f\n",polowienie(lewy, prawy, delta));



    return 0;
}
