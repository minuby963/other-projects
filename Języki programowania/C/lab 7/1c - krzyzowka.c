#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 109791

int szuka_slowa (int ile_liter, int ktora, char litera, int od, int *k)
{
    int i=1,j=0,a=0;
    char ciag[30];
    char znak='.';
    FILE *fp;
    fp = fopen("polski.txt","r");
    if (fp==0)
    {
        printf("nie udalo sie wczytac pliku\n");
        exit(-1);
    }
    while(i!=od)
    {
        fgets(ciag,30,fp);
        //printf("ciag = %s",ciag);
        i++;
    }
    //printf("ile liter = %d\n",ile_liter);
    for(i=0;i<30;i++)
    {
        //printf("i = %d\n",i);

        fscanf(fp,"%c",&znak);
        ciag[i]=znak;
        //printf("%c dla i = %d\n",ciag[i],i);
        //printf("i = %d\n",i);
        if(a==0)
        {
            if (i==ktora)
            {
                //printf("jest ///\n");
                if(znak==litera)
                {
                    a=1;
                }
            }
            else
            {
                    if(znak=='\n')
                    {
                        i=0;
                        //j++;
                        //if (j==10)
                        //    break;
                        continue;
                    }
            }
        }
        //printf("a = %d\n",a);
        if (a==1)
        {
            //printf("jest: a = %d\n",a);
            if (i==ile_liter+1)
            {
                if(znak=='\n')
                {
                    i=0;
                    printf("\nwiersz nr %d to: ",*k+1);
                    for(j=1;j<=ile_liter;j++)
                    {
                        printf("%c",ciag[j]);
                    }
                    break;
                }
                continue;
            }
            if(znak=='\n')
            {
                i=0;
                continue;
            }
        }
    }

    /*while (znak!='\n')
    {
        fscanf(fp,"%c",&znak);
        printf("%c",znak);
    }*/
}

int main()
{
    int i=0,b,c,od,ktora,ile_liter;
    char litera, znak='.';
    srand(time(NULL));
    b=rand();
    while (i<7)
    {
        c=rand()%100;
        od=((rand()*100)+c)%MAX;
        //printf("%d\n",od);
        printf("podaj dlugosc wiersza nr %d:                         ",i+1);
        scanf("%d",&ile_liter);
        printf("podaj ktora litera w wierszu nr %d to litera hasla:  ",i+1);
        scanf("%d",&ktora);
        if(ktora>ile_liter)
            continue;
        printf("podaj ja:                                           ");
        scanf("%c",&litera);
        scanf("%c",&litera);
        //od=16;
        szuka_slowa(ile_liter,ktora,litera,od,&i);
        printf("\n\n");
        i++;
    }

    return 0;
}
