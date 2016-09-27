#include <stdlib.h>
#include <stdio.h>
#define MAX 21474
int main ()
{
    FILE *fp;
    int i,j=1;
    int alf[MAX];
    char tab[MAX];

    char znak='.';
    char n='.';
    char koniec[30];
    fp=fopen("polski.txt","r");
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
    for (i=1;EOF;i++)
    {
        //printf("i = %d\n",i);
        fscanf(fp,"%c", &znak);
        if(i==1)
        {
            tab[0]=znak;
            printf("i = %d\n",i);
            alf[0]=i;
            printf("tab[0] = %c\n",tab[j-1]);
            printf("alf[0] = %d\n",alf[j-1]);
        }


        //printf("j = %d\n",j);
       // printf("znak = %c\n",znak);
        if (znak!=tab[j-1])
        {
            tab[j]=znak;
            alf[j]=i;
            printf("tab[j] = %c\n",tab[j]);
            printf("alf[j] = %d\n",alf[j]);
            j++;
        }
        fgets(koniec,30, fp);
        //fscanf(fp,"%c", &n);

        //printf("%s",koniec);
        //if(i>20)
            //break;
    }
    return 0;
}
