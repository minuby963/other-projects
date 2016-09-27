#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
void pisz(int p, int q, int r, int tab1[][q], int tab2[][r],int tab3[][r])
{
    int a,b,c,w=0;
    printf("\ntab3:\n");
    //printf("tab1[2][3] = %d\n",tab1[2][3]);
    for(c=0;c<p;c++)
    {
        for(b=0;b<r;b++)
        {
            w=0;
            for(a=0;a<q;a++)
            {
                w=w+tab1[c][a]*tab2[a][b];
            }
            tab3[c][b]=w;
            //printf("%4d",tab3[c][b]);
        }
        //printf("\n");
    }
}
*/
void wypelnij (int **tablica, int wiersze, int kolumny)
{
    int i, j;
    for(i=0;i<wiersze;i++)
    {
        for(j=0;j<kolumny;j++)
        {
            tablica[i][j]=i+j;    //rand()%100;     //i+j;
            printf("%4d",tablica[i][j]);
        }
        printf("\n");
    }
}

void podaj (int **tablica, int wiersze, int kolumny)
{
    int i, j;
    for(i=0;i<wiersze;i++)
    {
        for(j=0;j<kolumny;j++)
        {   scanf("%d",&tablica[i][j]);
            //printf("%4d",tablica[i][j]);
        }
        printf("\n");
    }
}

void wypelnij_losowo (int **tablica, int wiersze, int kolumny)
{
    int i, j;
    for(i=0;i<wiersze;i++)
    {
        for(j=0;j<kolumny;j++)
        {
            tablica[i][j]=rand()%50;     //i+j;
            printf("%4d",tablica[i][j]);
        }
        printf("\n");
    }
}

void mnoz (int **macierz1, int **macierz2, int **macierz3, int w1, int w2, int w3)
{
    int a, b, c, w=0;
    for(c=0;c<w1;c++)
    {
        for(b=0;b<w3;b++)
        {
            w=0;
            for(a=0;a<w2;a++)
            {
                w=w+macierz1[c][a]*macierz2[a][b];
            }
            macierz3[c][b]=w;
        }
    }
}

void czysc (int **tablica,int wiersze)
{
    int i;
    for(i=0;i<wiersze;i++)
    {
        free(tablica[i]);
    }
    free(tablica);
}
int main ()
{
    /*
    srand(time(NULL));
    int test;
    test=rand();
    int i, j;
    int p, q, r;
    p=5;
    q=3;
    r=4;
    int tab1[p][q];
    int tab2[q][r];
    int tab3[p][r];
    printf("tab1\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            tab1[i][j]=i+j;    //rand()%100;     //i+j;
            printf("%4d",tab1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("tab2\n");
    for(i=0;i<q;i++)
    {
        for(j=0;j<r;j++)
        {
            tab2[i][j]=i+j;       //rand()%100;  //i+j;
            printf("%4d",tab2[i][j]);
        }
        printf("\n");
    }
    pisz(p,q,r,tab1,tab2,tab3);

    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("%4d",tab3[i][j]);
        }
        printf("\n");
    }
    */


    //tablica dynamiczna
    srand(time(NULL));
    int x;
    x=rand();
    int i, j;
    int w1,w2,w3;
    int** tablica1;
    int** tablica2;
    int** tablica3;
    printf("podaj ilosc wierszy pierwszej macierzy: ");
    scanf("%d", &w1);
    printf("podaj ilosc kolumn pierwszej macierzy (i wierszy drugiej macierzy): ");
    scanf("%d", &w2);
    printf("podaj ilosc kolumn drugiej macierzy: ");
    scanf("%d", &w3);
    printf("\n1 - wypelnij macierz liczbami losowymi\n2 - podaj liczby z klawiatury \n");
    scanf("%d",&x);

    tablica1=malloc(w1*sizeof(int*));
    for(i=0;i<w1;i++)
    {
        tablica1[i]=malloc(w2*sizeof(int));
    }
    tablica2=malloc(w2*sizeof(int*));
    for(i=0;i<w2;i++)
    {
        tablica2[i]=malloc(w3*sizeof(int));
    }
    tablica3=malloc(w1*sizeof(int*));
    for(i=0;i<w1;i++)
    {
        tablica3[i]=malloc(w3*sizeof(int));
    }

    if(x==1)
    {
        printf("\nmacierz 1:\n");
        wypelnij_losowo(tablica1,w1,w2);
        printf("\nmacierz 2:\n");
        wypelnij_losowo(tablica2,w2,w3);
    }
    if(x==2)
    {
        printf("\nmacierz 1:\n");
        podaj(tablica1,w1,w2);
        printf("\nmacierz 2:\n");
        podaj(tablica2,w2,w3);
    }
    if(x==3)
    {
        printf("\nmacierz 1:\n");
        wypelnij(tablica1,w1,w2);
        printf("\nmacierz 2:\n");
        wypelnij(tablica2,w2,w3);
    }
    if((x<=3)&&(x>0))
    {
        printf("\nmacierz 1 * macierz 2 = \n");
        mnoz(tablica1,tablica2,tablica3,w1,w2,w3);
        for(i=0;i<w1;i++)
        {
            for(j=0;j<w3;j++)
            {
                printf("%5d",tablica3[i][j]);
            }
            printf("\n");
        }
    }
    czysc(tablica1,w1);
    czysc(tablica2,w2);
    czysc(tablica3,w1);
    return 0;
}
