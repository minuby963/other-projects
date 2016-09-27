/*
Dany jest plik tekstowy w którym mamy dane n studentów w postaci imiê,
nazwisko, numer albumu i ocena z piêciu przedmiotów.
Stwórz strukturê tego studenta i sprowadz dane z tego pliku,p
pózniej zapisz je do jednowymiarowej tablicy typu struct.

Napisz osobna funkcje numer 1, która utworzy nowa tablice typu struktury,
w ktorej bed¹ zapisane dane wszystkich studentów którzy maja zaliczone
wszystkie przedmioty. Wyœwietl ta tablice w main.

Napisz druga funkcje do ktorej wyœlesz numer albumu
(podany przez u¿ytkownika) i funkcja zwróci pozosta³e dane studenta.

Posortuj ta nowa tablice zaliczonych wed³ug numeru albumu lub wed³ug
œrednich ocen( wybiera u¿ytkownik) za pomoc¹ switch.
Wyœwietl ta nowa posortowana tablice i zapisz ja do pliku binarnego.
*/

#include <iostream>
#include <fstream>
using namespace std;


struct student
{
    string imie;
    string nazwisko;
    int nr_indeksu;
    double przedmiot1;
    double przedmiot2;
    double przedmiot3;
    double przedmiot4;
    double przedmiot5;
};

struct student *stworz_tablice_wszyscy (fstream & plik1)
{
    int rozmiar_tablicy=100; //TAK SIÊ NIE POWINNO ROBIC!!!
    int i=0;
    struct student * tab = new struct student[rozmiar_tablicy];

    while(!plik1.eof())
    {
        plik1>>tab[i].imie;
        plik1>>tab[i].nazwisko;
        plik1>>tab[i].nr_indeksu;
        plik1>>tab[i].przedmiot1;
        plik1>>tab[i].przedmiot2;
        plik1>>tab[i].przedmiot3;
        plik1>>tab[i].przedmiot4;
        plik1>>tab[i].przedmiot5;

        i++;
    }
    return tab;
}


struct student *stworz_tablice__studenci_ktorzy_otrzymali_zaliczenie (struct student *tab_wszystkie)
{
    int rozmiar_tablicy=100; //TAK SIÊ NIE POWINNO ROBIC!!!
    int i=0, j=0;
    student * tab = new student[rozmiar_tablicy];
    while(!(tab_wszystkie[j].imie==""))
    {
        if((tab_wszystkie[j].przedmiot1>=3) && (tab_wszystkie[j].przedmiot2>=3) && (tab_wszystkie[j].przedmiot3>=3) && (tab_wszystkie[j].przedmiot4>=3) && (tab_wszystkie[j].przedmiot5>=3))
        {
            tab[i].imie = tab_wszystkie[j].imie;
            tab[i].nazwisko = tab_wszystkie[j].nazwisko;
            tab[i].nr_indeksu = tab_wszystkie[j].nr_indeksu;
            tab[i].przedmiot1 = tab_wszystkie[j].przedmiot1;
            tab[i].przedmiot2 = tab_wszystkie[j].przedmiot2;
            tab[i].przedmiot3 = tab_wszystkie[j].przedmiot3;
            tab[i].przedmiot4 = tab_wszystkie[j].przedmiot4;
            tab[i].przedmiot5 = tab_wszystkie[j].przedmiot5;
            i++;
        }
        j++;
    }
    return tab;
}

void wyswietl_tablice(struct student *tab)
{
    int i=0;
    while(!(tab[i].imie==""))
    {

        printf("imie: %10s  nazwisko: %10s  nr. indeksu: %6d  oceny: %1.1f %1.1f %1.1f %1.1f %1.1f \n",tab[i].imie.c_str(),tab[i].nazwisko.c_str(),tab[i].nr_indeksu, tab[i].przedmiot1, tab[i].przedmiot2, tab[i].przedmiot3, tab[i].przedmiot4, tab[i].przedmiot5);
        //ten sposob wyswietlania jest w tym przypadku lepszy ale mozesz sprobowac ten nizej
        /*  wystarczy, ze odkomentujesz
        cout<<"imie: "<<tab[i].imie<<"; nazwisko: "<<tab[i].nazwisko<<"; nr_indeksu: ";
        cout<<tab[i].nr_indeksu<<"; przedmioty: "<<tab[i].przedmiot1<<" & "<<tab[i].przedmiot2;
        cout<<" & "<<tab[i].przedmiot3<<" & "<<tab[i].przedmiot4<<" & "<<tab[i].przedmiot5<<" "<<endl;
        */
        i++;
    }
    cout<<endl<<endl;
}

struct student * szukaj_studenta (int nr_ind,struct student *tab)
{
    int i=0;
    while(!(tab[i].imie==""))
    {
        if(tab[i].nr_indeksu==nr_ind)
            return tab+i;

        i++;
    }
    cout<<"Nie ma studenta o takim numerze indeksu!"<<endl;
    return NULL;
}
void zamien(struct student *tab,int i,int j)
{
    string imie, nazwisko;
    int nr_indeksu;
    double przedmiot1, przedmiot2, przedmiot3, przedmiot4, przedmiot5;

    imie = tab[i].imie;
    nazwisko = tab[i].nazwisko;
    nr_indeksu = tab[i].nr_indeksu;
    przedmiot1 = tab[i].przedmiot1;
    przedmiot2 = tab[i].przedmiot2;
    przedmiot3 = tab[i].przedmiot3;
    przedmiot4 = tab[i].przedmiot4;
    przedmiot5 = tab[i].przedmiot5;

    tab[i].imie = tab[j].imie ;
    tab[i].nazwisko = tab[j].nazwisko;
    tab[i].nr_indeksu = tab[j].nr_indeksu;
    tab[i].przedmiot1 = tab[j].przedmiot1;
    tab[i].przedmiot2 = tab[j].przedmiot2;
    tab[i].przedmiot3 = tab[j].przedmiot3;
    tab[i].przedmiot4 = tab[j].przedmiot4;
    tab[i].przedmiot5 = tab[j].przedmiot5;

    tab[j].imie = imie ;
    tab[j].nazwisko = nazwisko;
    tab[j].nr_indeksu = nr_indeksu;
    tab[j].przedmiot1 = przedmiot1;
    tab[j].przedmiot2 = przedmiot2;
    tab[j].przedmiot3 = przedmiot3;
    tab[j].przedmiot4 = przedmiot4;
    tab[j].przedmiot5 = przedmiot5;

}
void sortuj_nr_indeksu(struct student *tab)
{
    int i=0, j=0, k;
    int minimum;

    while(!(tab[j].imie==""))
    {
        minimum=tab[j].nr_indeksu;
        k=j;
        i=j;
        while(!(tab[i].imie==""))
        {
            if(minimum>tab[i].nr_indeksu)
            {
                minimum=tab[i].nr_indeksu;
                k=i;
            }
            i++;
        }
        if(k!=j)
            zamien(tab,j,k);
        j++;
    }
}

struct student *sortuj_srednia(struct student *tab)
{
    int i=0, j=0, k;
    double minimum;
    double sr;
    while(!(tab[j].imie==""))
    {
        minimum=(tab[j].przedmiot1+tab[j].przedmiot2+tab[j].przedmiot3+tab[j].przedmiot4+tab[j].przedmiot5)/5;
        k=j;
        i=j;
        while(!(tab[i].imie==""))
        {
            sr=(tab[i].przedmiot1+tab[i].przedmiot2+tab[i].przedmiot3+tab[i].przedmiot4+tab[i].przedmiot5)/5;
            if(minimum>sr)
            {
                minimum=sr;
                k=i;
            }
            i++;
        }
        if(k!=j)
            zamien(tab,j,k);
        j++;
    }
}
int main()
{
    fstream plik1;
    plik1.open("dane_frajera.txt", ios::in);
    int rozmiar_tablicy=100; //TAK SIÊ NIE POWINNO ROBIC!!!
    struct student *tab_wszystkie;
    struct student *tab_zdane;
    struct student *szukany_student;
    int jak_sortowac;
    int nr_ind;
    if(!plik1.good())
    {
        cout<<"Ups, nie udalo sie otworzyc pliku dane_frajera.txt :("<<endl;
        return 0;
    }

    tab_wszystkie=stworz_tablice_wszyscy(plik1);
    tab_zdane=stworz_tablice__studenci_ktorzy_otrzymali_zaliczenie(tab_wszystkie);

    cout<<endl<<"------ wszyscy studenci ------"<<endl<<endl;
    wyswietl_tablice(tab_wszystkie);
    /*
    niby mialo byc wyswietlone w main ale tak jest wygodniej,
    jak chcesz to przenies sobie z tej funkcji do main i
    zmien kazde tab na tab_wszystkie albo na tab_zdane
    */
    cout<<endl<<"------ studenci, ktorzy zaliczyli wszystkie przedmioty ------"<<endl<<endl;
    wyswietl_tablice(tab_zdane);

    cout<<"Podaj nr. indeksu studenta: "<<endl;
    cin>>nr_ind;
    szukany_student=szukaj_studenta(nr_ind, tab_wszystkie);

    if(szukany_student!=NULL)
    {
        cout<<endl<<"------ szukany student ------"<<endl<<endl;
        printf("imie: %10s  nazwisko: %10s  nr. indeksu: %6d  oceny: %1.1f %1.1f %1.1f %1.1f %1.1f \n",szukany_student->imie.c_str(),szukany_student->nazwisko.c_str(),szukany_student->nr_indeksu, szukany_student->przedmiot1, szukany_student->przedmiot2, szukany_student->przedmiot3, szukany_student->przedmiot4, szukany_student->przedmiot5);
    }

    cout<<endl<<"1 - sortuj wedlug nr. indeksu"<<endl;
    cout<<"2 - sortuj wedlug sredniej ocen"<<endl;
    cin>>jak_sortowac;
    switch(jak_sortowac)
    {
        case 1:
            sortuj_nr_indeksu(tab_zdane);
            break;
        case 2:
            sortuj_srednia(tab_zdane);
            break;
    }
    cout<<endl<<"------ studenci, ktorzy zaliczyli wszystkie przedmioty po sortowaniu ------"<<endl<<endl;
    wyswietl_tablice(tab_zdane);




    ofstream plik2("frajer_output.txt", ios::binary);

    if(!plik2.good())
    {
        cout<<"Ups, nie udalo sie otworzyc pliku frajer_output.txt :("<<endl;
        return 0;
    }
    int n=0;
    while(!(tab_zdane[n].imie==""))
    {
        plik2.write(( const char * ) & tab_zdane[n], sizeof *tab_zdane );
        n++;
    }

    delete [] tab_wszystkie;
    delete [] tab_zdane;
    plik1.close();
    plik2.close();
    return 0;
}
