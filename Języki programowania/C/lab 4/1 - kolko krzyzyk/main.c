#include <stdio.h>
//#include <stdlib.h>
int tab[3][3];

void uzupelnij ()
{
    int a=1;
    int i;
    int j;
    for (i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
           tab[j][i]=a;
           a++;
        }
    }
}

void wyswietl ()
{
    int i;
    int j;
    for (i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%5d",tab[j][i]);
        }
        printf("\n\n");
    }
}

int sprawdz_ruch (int ruch, int znak)
{
    int i;
    int j;
    for (i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            //printf("i = %d\n",i);
            if (tab[j][i] == ruch)
            {
                //printf("tab[j][i] = %d\n",tab[j][i]);
                //printf("mod znak 1= %d\n", znak%2);
                if (znak%2==0)
                    tab[j][i]=0;
                else
                    tab[j][i]=11;
                //printf("tab[j][i] = %d\n",tab[j][i]);
                //printf("znak = %d\n",znak);
                return 1;
            }
        }
    }
    return 0;
}

int sprawdza_wygrana (int znak)
{
    int i;
    if(znak==12)
    {
        //printf("\nremis!!!\n");
        //return 1;
    }
    else
    {
        //printf("sprawdza... 1\n");
        for (i=0;i<3;i++)
        {
            if ((tab[0][i]==tab[1][i]) && (tab[0][i]==tab[2][i]))
            {
                //printf("sprawdza... 2, i = %d\n",i);
                return 0;
            }
        }
        for (i=0;i<3;i++)
        {
            if ((tab[i][0]==tab[i][1]) && (tab[i][0]==tab[i][2]))
            {
                //printf("sprawdza... 3, j = %d\n",i);
                return 0;
            }
        }
        if ((tab[0][0]==tab[1][1]) && (tab[0][0]==tab[2][2]))
        {
            //printf("sprawdza... 4\n");
            return 0;
        }
        printf("\n");
        if ((tab[2][0]==tab[1][1]) && (tab[2][0]==tab[0][2]))
        {
            //printf("sprawdza... 5\n");
            return 0;
        }
        //printf("sprawdza... 6\n");
    }
    return 1;
}

int losuje ()
{
    int a;
    int b;
    b=rand();
    a=(rand()%10)+1;
    printf("\n a = %d \n",a);
    return a;
}

int single ()
{
    int ruch=0;
    int znak=2;
    uzupelnij ();
    printf("\n\n\n\n\n\n\n0 - kolko\n11 - krzyzyk\n\n\n\n\n\n\n\n\n");
    wyswietl ();
    for(;znak<11;)
    {
        while (ruch>9 || ruch<1)
        {
            if (znak%2==0)
                printf("ruch kolka \n");
            else
                printf("ruch krzyzyka \n");

            scanf("%d", &ruch);
            if (sprawdz_ruch (ruch, znak)==0)
                ruch=0;
        }
        printf("\n\n\n\n\n\n\n0 - kolko\n10 - krzyzyk\n\n\n\n\n\n\n\n\n");
        wyswietl ();
        znak++;
        ruch=0;
        if(znak>4)
        {
            if (sprawdza_wygrana(znak)==0)
            {
                //printf("mod znak 2= %d\n", (znak+1)%2);
                if ((znak+1)%2==0)
                    printf("\n\nwygralo kolko!!! \n\n");
                else
                    printf("\n\nwygral krzyzyk!!! \n\n");
                znak=15;
            }
        }
    }
    if(znak==11)
        printf("remis!!!\n");
}

int komp (int znak)
{
    int a;
    if(((znak%2)+1)==0)
        a=0;
    else
        a=11;
    int i;
    printf("\nprzed spr 1 \n");
    for (i=0;i<3;i++)
    {
        if (tab[0][i]==tab[1][i])
        {
            if(tab[2][i] == 0 || tab[2][i] == 11)
                break;
            else
            {
                tab[2][i]=a;
                printf("\nspr 1 \n");
                return 0;
            }
        }
    }
    printf("\nprzed spr 2 \n");
    for (i=0;i<3;i++)
    {
        if (tab[1][i]==tab[2][i])
        {
            if(tab[0][i] == 0 || tab[0][i] == 11)
                break;
            else
            {
                tab[0][i]=a;
                printf("\nspr 2 \n");
                return 0;
            }
        }
    }
    printf("\nprzed spr 3 \n");
    for (i=0;i<3;i++)
    {
        if (tab[i][0]==tab[i][1])
        {
            if(tab[i][2] == 0 || tab[i][2] == 11)
                break;
            else
            {
                tab[i][2]=a;
                printf("\nspr 3 \n");
                return 0;
            }
        }
    }
    printf("\nprzed spr 4 \n");
    for (i=0;i<3;i++)
    {
        if (tab[i][1]==tab[i][2])
        {
            if(tab[i][0] == 0 || tab[i][0] == 11)
                break;
            else
            {
                tab[i][0]=a;
                printf("\nspr 4 \n");
                return 0;
            }
        }
    }
    printf("\nprzed spr 5 \n");
    for (i=0;i<3;i++)
    {
        if (tab[0][i]==tab[2][i])
        {
            if(tab[1][i] == 0 || tab[1][i] == 11)
                break;
            else
            {
                tab[1][i]=a;
                printf("\nspr 5 \n");
                return 0;
            }
        }
    }
    printf("\nprzed spr 6 \n");
    for (i=0;i<3;i++)
    {
        if (tab[i][0]==tab[i][2])
        {
            if(tab[i][1] == 0 || tab[i][1] == 11)
                break;
            else
            {
                tab[i][1]=a;
                printf("\nspr 6 \n");
                return 0;
            }
        }
    }
    printf("\nprzed spr 7 \n");
    if (tab[0][0]==tab[1][1])
    {
        if(tab[2][2] == 0 || tab[2][2] == 11)
        {

        }
        else
        {
            tab[2][2]=a;
            printf("\nspr 7 \n");
            return 0;
        }
    }
    printf("\nprzed spr 8 \n");
    if (tab[0][0]==tab[2][2])
    {
        if(tab[1][1] == 0 || tab[1][1] == 11)
        {

        }
        else
        {
            tab[1][1]=a;
            printf("\nspr 8 \n");
            return 0;
        }
    }
    printf("\nprzed spr 9 \n");
    if (tab[1][1]==tab[2][2])
    {
        if(tab[0][0] == 0 || tab[0][0] == 11)
        {

        }
        else
        {
            tab[0][0]=a;
            printf("\nspr 9 \n");
            return 0;
        }
    }
    printf("\nprzed spr 10 \n");
    if (tab[2][0]==tab[1][1])
    {
        if(tab[0][2] == 0 || tab[0][2] == 11)
        {

        }
        else
        {
            tab[0][2]=a;
            printf("\nspr 10 \n");
            return 0;
        }
    }
    printf("\nprzed spr 11 \n");
    if (tab[2][0]==tab[0][2])
    {
        if(tab[1][1] == 0 || tab[1][1] == 11)
        {

        }
        else
        {
            tab[1][1]=a;
            printf("\nspr 11 \n");
            return 0;
        }
    }
    printf("\nprzed spr 12 \n");
    if (tab[0][2]==tab[1][1])
    {
        if(tab[2][0] == 0 || tab[2][0] == 11)
        {

        }
        else
        {
            tab[2][0]=a;
            printf("\nspr 12 \n");
            return 0;
        }
    }
    return 1;
}

int multi ()
{
    int ruch=0;
    int znak=2;
    uzupelnij ();
    printf("\n\n\n\n\n\n\n0 - kolko\n11 - krzyzyk\n\n\n\n\n\n\n\n\n");
    wyswietl ();
    for(;znak<11;)
    {
        while (ruch>9 || ruch<1)
        {
            if (znak%2==0)
            {
                printf("ruch kolka \n");
                scanf("%d", &ruch);
            }
            else
            {
                printf("ruch krzyzyka \n");
                if(komp (znak)==1)
                    ruch =losuje ();
                else
                    break;

                printf("ruch = %d\n",ruch);
            }
            if (sprawdz_ruch (ruch, znak)==0)
                ruch=0;
        }
        printf("\n\n\n\n\n\n\n0 - kolko\n10 - krzyzyk\n\n\n\n\n\n\n\n\n");
        wyswietl ();
        znak++;
        ruch=0;
        if(znak>4)
        {
            if (sprawdza_wygrana(znak)==0)
            {
                //printf("mod znak 2= %d\n", (znak+1)%2);
                if ((znak+1)%2==0)
                    printf("\n\nwygralo kolko!!! \n\n");
                else
                    printf("\n\nwygral krzyzyk!!! \n\n");
                znak=15;
            }
        }
    }
    if(znak==11)
        printf("remis!!!\n");
}

int main()
{

    char a='D';
    while (a!='A' && a!='B' && a!='C')
    {
        printf("wybierz: \n\n A - 1 vs 1 \n B - 1 vs com \n C - wyjdz z gry\n\n");
        scanf("%c",&a);
        //printf("%c", a);
        if (a == 'A')
            single ();
        else
        {
            if(a == 'B')
                multi();
            else
            {
                if(a=='C')
                    break;
            }
        continue;
        }
    }
    return 0;
}
