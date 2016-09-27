#include <stdio.h>

int main ()
{
    int i;
    char str1[50];
    char str2[50];
    printf("podaj 1 ciag\n");
    scanf("%s", str1);
    printf("podaj 2 ciag\n");
    scanf("%s", str2);
    //printf("%s\n%s\n",str1,str2);
    while(str1[i]==str2[i])
        i++;
    printf("%d",i);
}
