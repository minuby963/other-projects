#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trans (int **tab,int **tab2,int *x,int *y)
{
    int swap,i,j,tmp;
    tab2=(int**)malloc(sizeof(int)*(*y));
    for(i=0;i<*x;i++)
    {
        tab2[i]=(int*)malloc(sizeof(int)*(*x));
    }
    for(i=0;i<*y;i++)
    {
        for(j=0;j<*y;j++)
        {
            tab2[j][i]=tab[i][j];
        }
    }
}

void wyswietl (int **tab,int x,int y)
{
    int i, j;
    static int licznik=0;
    licznik++;
    printf("%d\n",licznik);
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            printf("%2d",tab[i][j]);
        }
        printf("\n");
    }
}
void losuj  (int **tab,int x,int y)
{
    int i, j;
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            tab[i][j]=rand()%10;
        }
    }
}
int main ()
{
    int x,y,i,j,random;
    srand(time(NULL));
    random=rand();
    printf("podaj x: ");
    scanf("%d", &x);
    printf("podaj y: ");
    scanf("%d", &y);
    int **tab;
    int **tabt;
    tab=(int**)malloc(sizeof(int)*x);
    for(i=0;i<x;i++)
    {
        tab[i]=(int*)malloc(sizeof(int)*y);
    }
    losuj(tab,x,y);
    wyswietl(tab,x,y);
    trans(tab,tabt,&x,&y);
    wyswietl(tabt,y,x);

    return 0;
}
