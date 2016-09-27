#include <stdio.h>

struct kart
{
    int dane;
    struct kart *next;
};

void dodaj(struct kart **poczatek,int dane)
{
    struct kart *tmp;
    tmp=(struct kart*)malloc(sizeof(struct kart));
    tmp->dane=dane;
    tmp->next=*poczatek;
    *poczatek=tmp;

}
void wyswietl (struct kart *poczatek)
{
    struct kart *tmp;
    tmp=poczatek;
    while (tmp!=NULL)
    {
        printf("dane: %d\n",tmp->dane);
        tmp=tmp->next;
    }
    printf("\n");
}

void odwroc (struct kart **poczatek)
{
    struct kart *tmp1,*tmp2,*tmp3;
    tmp1=*poczatek;
    tmp2=tmp1->next;
    tmp3=tmp2->next;
    while (tmp3!=NULL)
    {
        printf("asd\n");
        tmp2->next=tmp1;
        tmp1=tmp2;
        tmp2=tmp3;
        tmp3=tmp3->next;
    }
    tmp2->next=tmp1;
    (*poczatek)->next=NULL;
    *poczatek=tmp2;

}

int main ()
{
    struct kart *poczatek;
    poczatek=NULL;

    dodaj(&poczatek, 4);
    dodaj(&poczatek, 3);
    dodaj(&poczatek, 6);
    wyswietl (poczatek);
    dodaj(&poczatek, 9);
    dodaj(&poczatek, 34);
    dodaj(&poczatek, 1);
    dodaj(&poczatek, 2);
    wyswietl (poczatek);
    odwroc (&poczatek);
    wyswietl (poczatek);
    return 0;
}
