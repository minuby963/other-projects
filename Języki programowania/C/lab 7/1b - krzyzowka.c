#include <stdlib.h>
#include <stdio.h>
#define MAX 21474

void wpisz_wiersze (int krzyzowka[])
{
    int i;
    printf("podaj ilosc liter w kolejnych wierszach dla hasla student\n");
    for(i=0;i<7;i++)
    {
       scanf("%d",krzyzowka[i]);
    }
}

int main ()
{
    FILE *fp;
    int i,j=1;
    int alf[MAX];
    char tab[MAX];
    int krzyzowka[7];
    char znak='.';
    char n='.';
    char koniec[30];
    fp=fopen("polski1.txt","r");
    if (fp==0)
    {
        printf("nie udalo sie wczytac pliku\n");
        exit;
    }
    else
    {
        printf("wczytano plik\n");
    }
    tab[0]=',';
    for (i=1;!EOF;i++)
    {
        fscanf(fp,"%c", &znak);
        printf("znak = %c\n",znak);
        if(i==1)
        {
            tab[0]=znak;
            printf("i = %d\n",i);
            alf[0]=i;
            //printf("tab[0] = %c\n",tab[j-1]);
            //printf("alf[0] = %d\n",alf[j-1]);
        }
        if (znak!=tab[j-1])
        {
            tab[j]=znak;
            alf[j]=i;
            //printf("tab[j] = %c\n",tab[j]);
            //printf("alf[j] = %d\n",alf[j]);
            j++;
        }
        //fgets(koniec,30, fp);
        //fscanf(fp,"%s",koniec);
        //fscanf(fp,"%c", &znak);
        printf("koniec = %s\n",koniec);
    }
    wpisz_wiersze (krzyzowka[7]);
    return 0;
}
