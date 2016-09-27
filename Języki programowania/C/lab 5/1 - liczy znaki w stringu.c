#include <stdio.h>

int main ()
{
    char string[50];
    int tab[50];
    char str[0];
    str[0]=' ';
    int i, j, a=0, b=0,c=0;
    printf("podaj ciag znakow\n");
    scanf("%s",string);
    //printf("%s\n",string);
    for(j=0;j<50;j++)
    {
         for(i=0;i<50;i++)
        {
            if(string[j]==str[0])
                break;
            if(string[j]==string[i])
            {
                a++;
            }
        }
        //printf("a = %d\n",a);
        tab[j]=a;
        a=0;
        if((j!=0) &&(tab[j]>c))
        {
            b=j;
            c=tab[j];
        }
        //printf("b = %d\n",b);
    }
    printf("\nznak '%c' wysptepuje %d razy\n",string[b],c);
    return 0;
}
