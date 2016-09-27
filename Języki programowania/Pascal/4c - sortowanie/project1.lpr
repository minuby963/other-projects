program project1;
uses DOS;

const ILOSC = 10;
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

procedure quick_sort2 (tab: tablica; poczatek:integer; koniec:integer);
var i, j, podzial, swap:integer;
begin
   podzial:=(poczatek+koniec)div(2);
   i:=poczatek;
   j:=koniec;
   writeln;
   writeln;
   writeln('podzial = ', podzial,'  tab[podzial] = ',tab[podzial]);
   writeln('poczatek = ', poczatek,'  tab[poczatek] = ',tab[poczatek]);
   writeln('koniec = ', koniec,'  tab[koniec] = ',tab[koniec]);
   while (i<=podzial) do
   begin
     if(tab[i]>tab[podzial+1]) then
     begin
       writeln('i = ', i,'  tab[i] = ',tab[i]);
       while(j>podzial) do
       begin
         if(tab[j]<tab[podzial]) then
         begin
           writeln('j = ', j,'  tab[j] = ',tab[j]);
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

   writeln;
   writeln('sortowanie metoda quicksort: ');
   for i:=0 to ILOSC do
   begin
     write(tab[i],', ');
   end;
   writeln;






   if (poczatek<podzial) then
   begin
     quick_sort2 (tab,poczatek,podzial);
   end;
   if (podzial+1<koniec) then
   begin
     quick_sort2 (tab,podzial+1,koniec);
   end;


   {if((poczatek)<>podzial-1) then
   begin

   end;

   if(((podzial+1)<>koniec) and (podzial+2<>koniec)) then
   begin
       quick_sort (tab,podzial+1,koniec);
   end;}


end;

procedure quick_sort3 (tab: tablica; poczatek:integer; koniec:integer);
var i, j, podzial, swap:integer;
begin
   podzial:=(poczatek+koniec)div(2);
   i:=poczatek;
   j:=koniec;
   writeln('podzial = ', podzial);

   while (i<=j) do
   begin

     while (tab[i]<tab[podzial]) do
     begin
       i:=i+1;
     end;

     while(tab[j]>tab[podzial]) do
     begin
       j:=j-1;
     end;

     if (i<=j) then
     begin
       swap:=tab[i];
       tab[i]:=tab[j];
       tab[j]:=swap;
       i:=i+1;
       j:=j-1;
     end;
   end;

       writeln;
      writeln('quicksort: ');
      for i:=0 to ILOSC do
      begin
        write(tab[i],', ');
      end;
      writeln;

   while i>j do
   begin
     if (poczatek<j) then
     begin
       quick_sort3 (tab,poczatek,j);
     end;

     if(i<koniec) then
     begin
       quick_sort3 (tab,i,koniec);
     end;
   end;


   {if ((poczatek=0) and (koniec=ILOSC)) then
   begin}
      writeln;
      writeln('sortowanie metoda quicksort end: ');
      for i:=0 to ILOSC do
      begin
        write(tab[i],', ');
      end;
      writeln;
   {end;}




   {    quick_sort (tab,podzial+1,koniec);

     quick_sort (tab,poczatek,podzial-1); }

end;

Procedure quicksort (Tablica1: tablica; Od:integer; Do_:integer);
Var
i,j : Integer;
x,temp : Integer;
Begin
i:=Od;
j:=Do_;
X:=Tablica1[ (Od+Do_) div 2];
Repeat
While Tablica1[i]<x do i:=i+1;
While x<Tablica1[j] do j:=j-1;
if i<=j Then
Begin
Temp:=Tablica1[i];
Tablica1[i]:=Tablica1[j];
Tablica1[j]:=Temp;
i:=i+1;
j:=j-1;
End;
Until i>j;
if Od<j Then quicksort(Tablica1,Od,j);
if i<Do_ Then quicksort(Tablica1,i,Do_);
End;



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
    quicksort (tab,0,ILOSC);
    {kopiec (tab);}
    readln;
end.
