#include <stdio.h>
#include <string.h>

int main()
{
    FILE *plik;
    char str[30];
    int liczba;
    plik=fopen("plik.txt","r");
    if(plik<=0)
    {
        printf("nie mozna otworzyc pliku\n");
        return 0;
    }
    fscanf(plik,"%d",&liczba);

    printf("%d\n",liczba);
    while(feof(plik)==0)
    {
         fscanf(plik,"%s",str);
         printf("%s\n",str);
    }


    fclose(plik);
    return 0;
}
