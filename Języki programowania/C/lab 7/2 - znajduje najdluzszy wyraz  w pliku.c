#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char wyraz[30];
    char wynik[30];
    char znak;
    int i=0,j,k, a=0;
    FILE *fp;
    fp=fopen("polski.txt","r");
    if(fp==0)
    {
        printf("nie udalo sie otworzyc pliku");
        exit(-1);
    }
    for(i=0;i<109791;i++)
    {
        fgets(wyraz, 30, fp);
        //printf("wyraz = %s\n",wyraz);
        for(j=0;j<30;j++)
        {
            if(a<j)
            {
                a=j;
                for(k=0;k<30;k++)
                {
                    wynik[k]=wyraz[k];
                }
            }
            if (wyraz[j]=='\n')
            {
                //printf("true");
                j=0;
                break;
            }
        }
    }
    printf("liczba znakow = %d\n",a);
    printf("wyraz: %s\n", wynik);
    return 0;
}
