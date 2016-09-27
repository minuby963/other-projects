
int potega (int i, int poczatkowy)
{
    int a;
    int wynik = 1;
    if (i==0)
        return 1;
    if (i<0)
        return 0;
    for(a=0;a<i;a++)
    {
        wynik = wynik*poczatkowy;
    }
    return wynik;
}

int na_dziesietny (int poczatkowy, int liczba)
{
    int wynik = 0;
    int cyfra=0;
    int zmieniona = 0;
    int i, j=9, k;
    for (i=1;i<=10;i++)
    {
        //printf("\n j = %d \n",j);
        if (liczba<j)
            break;
        j=j*10 +9;
    }
    //printf("\n i = %d \n", i);
    for(k=0;k<i;k++)
    {
        if (k==0)
            cyfra = liczba%potega (k+1, 10);
        else
            cyfra = (liczba%potega (k+1,10) - liczba%potega (k,10))/potega (k,10);
        //printf ("cyfra = %d\n",cyfra);
        zmieniona = cyfra * potega(k,poczatkowy);
        //printf ("zmieniona = %d\n",zmieniona);
        wynik = wynik + zmieniona;
        //printf ("wynik = %d\n",wynik);
    }
    return wynik;
}

void z_dziesietnego (int system, int liczba)
{
    int i;
    int j;
    int tab [40];
    /*
    for(j=0;j<10;j++)
        tab[j]=9;
    */
    liczba=liczba*system;
    for(i=0;liczba>=system;i++)
    {
        liczba=liczba/system;
        //printf("\n liczba = %d \n",liczba);
        tab[i]=liczba%system;
        //printf("tab[%d] = %d \n",i,tab[i]);
    }
    //printf("\n i = %d \n\n",i);
    i--;
    for(;i>=0;i--)
    {
        printf("%d",tab[i]);
    }
}

int main ()
{
    int liczba;
    int system;
    int poczatkowy;
    do
    {
        printf("***                                                                        *** \n");
        printf("*** Program obsluguje tylko systemy od dwojkowego do dziesietnego wlacznie *** \n");
        printf("***                                                                        *** \n\n");
        printf("podaj liczbe:                                    ");
        scanf("%d",&liczba);
        printf("podaj w jakim systemie jest liczba:              ");
        scanf("%d",&poczatkowy);
        if (poczatkowy == 10)
        {
            printf("podaj na jaki system chcesz zamienic liczbe:     ");
            scanf("%d", &system);
        }
        else
        {
            system = 10;
        }
    }
    while (poczatkowy>10 || system>10);
    printf("\n\n\nliczba %d w systemie %d wynosi:    ",liczba, system);
    if (poczatkowy==10)
    {
        z_dziesietnego (system, liczba );
    }
    else
    {
        printf("%d ",na_dziesietny (poczatkowy, liczba) );
    }
    printf("\n\n\n");
    return 0;
}
