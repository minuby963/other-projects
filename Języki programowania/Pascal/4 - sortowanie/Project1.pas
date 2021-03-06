program project1;
uses DOS;

const ILOSC = 15;
TYPE tablica = array[0..ILOSC]of Integer;
var tab: tablica;
    i: integer;

procedure babelkowe(tab: tablica);
var i, j, gotowe, swap:integer;
begin
   i:=ILOSC;
   gotowe:=0;
   while i>0 do
   begin
     gotowe:=0;
     j:=0;
     while j<i do
     begin
        if tab[j]>tab[j+1] then
        begin
            swap:=tab[j];
            tab[j]:=tab[j+1];
            tab[j+1]:=swap;
            gotowe:=gotowe+1;
        end;
        j:=j+1;
     end;
     if gotowe=0 then
     begin
         break;
     end;
     i:=i-1;
   end;
   writeln;
   writeln;
   writeln('sortowanie babelkowe: ');
   for i:=0 to ILOSC do
   begin
     write(tab[i],', ');
   end;
   writeln;
end;

procedure wybieranie (tab: tablica);
var i, j, swap, min:integer;
begin
   i:=0;
   while i<=ILOSC do
   begin
     j:=i;
     min:=i;
     while j<=ILOSC do
     begin
       if tab[min]>tab[j] then
       begin
       min:=j;
       end;
       j:=j+1;
     end;
     swap:=tab[i];
     tab[i]:=tab[min];
     tab[min]:=swap;
     i:=i+1;
   end;
   writeln;
   writeln('sortowanie przez wybieranie: ');
   for i:=0 to ILOSC do
   begin
     write(tab[i],', ');
   end;
   writeln;
end;

procedure wstawianie (tab: tablica);
var i, j, swap:integer;
begin
   j:=0;
   while(j<=ILOSC-1) do
   begin
     i:=j;
     while (i>=0) do
     begin
        if (tab[i]>tab[i+1]) then
        begin
           swap:=tab[i];
           tab[i]:=tab[i+1];
           tab[i+1]:=swap;
        end;
        i:=i-1;
     end;
     j:=j+1;
   end;
   writeln;
   writeln('sortowanie przez wstawianie: ');
   for i:=0 to ILOSC do
   begin
     write(tab[i],', ');
   end;
   writeln;
end;

procedure wyswietl (tab:tablica);
begin
   writeln;
   writeln('sortowanie metoda quicksort: ');
   for i:=0 to ILOSC do
   begin
     write(tab[i],', ');
   end;
   writeln
end;

procedure quick_sort (tab: tablica; poczatek:integer; koniec:integer);
var i, j, podzial, swap:integer;
begin
   podzial:=(poczatek+koniec)div(2);
   i:=poczatek;
   j:=koniec;
   writeln('podzial = ', podzial);
   while (i<=podzial) do
   begin
     if(tab[i]>tab[podzial]) then
     begin
       writeln('i = ', i);
       while(j>podzial) do
       begin
         if(tab[j]<tab[podzial]) then
         begin
           writeln('j = ', j);
           swap:=tab[j];
           tab[j]:=tab[i];
           tab[i]:=swap;
           break;
         end;
         j:=j-1;
       end;
       if(j=podzial) then
       begin
         break;
       end;
     end;
     i:=i+1
   end;
   if((podzial+1)<>koniec) then
   begin
     quick_sort (tab,podzial+1,koniec);
   end;
   if((poczatek)<>podzial-1) then
   begin
     quick_sort (tab,poczatek,podzial-1);
   end;
   writeln;
   writeln('sortowanie metoda quicksort: ');
   for i:=0 to ILOSC do
   begin
     write(tab[i],', ');
   end;
   writeln
end;

procedure quick_sort2 (tab: tablica; poczatek:integer; koniec:integer);
var i, j, podzial, swap:integer;
begin
   podzial:=(poczatek+koniec)div(2);
   i:=poczatek;
   j:=koniec;
   writeln('podzial = ', podzial);
   while (i<=podzial) do
   begin
     if(tab[i]>tab[podzial]) then
     begin
       writeln('i = ', i);
       while(j>podzial) do
       begin
         if(tab[j]<tab[podzial]) then
         begin
           writeln('j = ', j);
           swap:=tab[j];
           tab[j]:=tab[i];
           tab[i]:=swap;
           break;
         end;
         j:=j-1;
       end;
       if(j=podzial) then
       begin
         break;
       end;
     end;
     i:=i+1
   end;
   if(poczatek=podzial) then
   begin
     if(podzial=koniec) then
     begin
       writeln;
       writeln('sortowanie metoda quicksort: ');
       for i:=0 to ILOSC do
       begin
         write(tab[i],', ');
       end;
       writeln
     end
     else
     begin
       quick_sort (tab,podzial+1,koniec);
     end;
   end
   else
   begin
     quick_sort (tab,poczatek,podzial-1);
   end;
end;

procedure kopiec (tab: tablica);
var i, j, swap:integer;
begin




   writeln;
   writeln('sortowanie przez kopcowanie: ');
   for i:=0 to ILOSC do
   begin
     write(tab[i],', ');
   end;
   writeln
end;


begin
    randomize;
    writeln('losowe liczby: ');
    for i:=0 to ILOSC do
    begin
      tab[i]:=random(100);
      write(tab[i],', ');
    end;
    babelkowe (tab);
    wybieranie (tab);
    wstawianie (tab);
    quick_sort (tab,0,ILOSC);
    {kopiec (tab);}
    readln;
end.
