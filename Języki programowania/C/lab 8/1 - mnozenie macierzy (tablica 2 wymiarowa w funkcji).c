#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int pisz(int p, int q, int r,int *i,int *j, int tab1[][q], int tab2[][r])
{
    int b,w=0;
    for(b=0;b<q;b++)
    {
        w=w+tab1[*i][b]*tab2[b][*j];
    }
    return w;
}

int main ()
{
    /*char t1[]={'l','u','t','y','\0'};
    char t2[]="luty";
    char *p;
    printf("%s\n",t2);
    printf("%s\n",t1);
    p="maj";
    printf("%c%c%c\n",*p,*(p+1),*(p+2));*/

    srand(time(NULL));
    int test;
    test=rand();
    int i, j;
    int p, q, r;
    p=10;
    q=6;
    r=11;
    int tab1[p][q];
    int tab2[q][r];
    int tab3[p][r];
    printf("tab1\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            tab1[i][j]=rand()%100;     //i+j;
            printf("%7d",tab1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("tab2\n");
    for(i=0;i<q;i++)
    {
        for(j=0;j<r;j++)
        {
            tab2[i][j]=rand()%100;  //i+j;
            printf("%7d",tab2[i][j]);
        }
        printf("\n");
    }
    printf("\ntab3:\n");
    for (i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            tab3[i][j]=pisz(p,q,r,&i,&j,tab1,tab2);
            printf("%7d",tab3[i][j]);
        }
        printf("\n");
    }
    return 0;
}
