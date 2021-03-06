program project1;

uses DOS;
const ILOSC = 50;
TYPE tablica = array[1..ILOSC]of Integer;
var tab: tablica;
    i: integer;
    tabQ: array[1..ILOSC] of integer;

procedure babelkowe(tab: tablica);
var i, j, gotowe, swap:integer;
begin
   i:=ILOSC;
   while i>0 do
   begin
     gotowe:=1;
     j:=1;
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
     if gotowe=1 then
     begin
         break;
     end;
     i:=i-1;
   end;
   writeln;
   writeln;
   writeln('sortowanie babelkowe: ');
   for i:=1 to ILOSC do
   begin
     write(tab[i],', ');
   end;
   writeln;
end;

procedure wybieranie (tab: tablica);
var i, j, swap, min:integer;
begin
   i:=1;
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
   for i:=1 to ILOSC do
   begin
     write(tab[i],', ');
   end;
   writeln;
end;

procedure wstawianie (tab: tablica);
var i, j, swap:integer;
begin
   j:=1;
   while(j<=ILOSC-1) do
   begin
     i:=j;
     while (i>=1) do
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
   for i:=1 to ILOSC do
   begin
     write(tab[i],', ');
   end;
   writeln;
end;

procedure quicksort (poczatek:integer; koniec:integer);
var i, j:integer;
    podzial:integer;
begin
   podzial:=tabQ[poczatek];
   i:=poczatek;
   j:=koniec;
   while (poczatek<koniec) do
   begin
     while ((tabQ[koniec] >= podzial) AND (poczatek < koniec)) do
     begin
       koniec := koniec - 1;
     end;
     If (poczatek <> koniec) then
     begin
       tabQ[poczatek] := tabQ[koniec];
       poczatek := poczatek + 1;
     end;
     while ((tabQ[poczatek] <= podzial) AND (poczatek < koniec)) do
     begin
       poczatek := poczatek + 1;
     end;

     if (poczatek <> koniec) then
     begin
       tabQ[koniec] := tabQ[poczatek];
       koniec := koniec - 1;
     end;
   end;
   tabQ[poczatek] := podzial;
   podzial := poczatek;
   poczatek := i;
   koniec := j;
   if (poczatek < podzial) then
   begin
      quicksort(poczatek, podzial-1);
   end;
   if (koniec > podzial) then
   begin
      quicksort(poczatek+1,koniec);
   end;
end;

procedure kopiec(tab:tablica);
var i,j,k,m,swap : integer;
begin
  for i := 2 to ILOSC do
  begin
    j := i;
    k := j div 2;
    swap := tab[i];
    while (k > 0) and (tab[k] < swap) do
    begin
      tab[j] := tab[k];
      j := k;
      k := j div 2;
    end;
    tab[j] := swap;
  end;
  for i := ILOSC downto 2 do
  begin
    swap := tab[1];
    tab[1] := tab[i];
    tab[i] := swap;
    j := 1; k := 2;
    while k < i do
    begin
      if (k + 1 < i) and (tab[k + 1] > tab[k]) then
      begin
        m := k + 1
      end
      else
      begin
        m := k;
      end;
      if tab[m] <= tab[j] then break;
      swap := tab[j];
      tab[j] := tab[m];
      tab[m] := swap;
      j := m;
      k := j + j;
    end;
  end;
  writeln;
  writeln;
  writeln('sortowanie przez kopcowanie:');
  for i := 1 to ILOSC do
  begin
    write(tab[i],', ');
  end;
  writeln;
end;

begin
    randomize;
    writeln('losowe liczby: ');
    for i:=1 to ILOSC do
    begin
      tab[i]:=random(100);
      tabQ[i]:=tab[i];
      write(tab[i],', ');
    end;
    babelkowe (tab);
    wybieranie (tab);
    wstawianie (tab);
    quicksort (1,ILOSC);
    writeln;
    writeln('sortowanie metoda quicksort: ');
    for i:=1 to ILOSC do
    begin
      write(tabQ[i],', ');
    end;
    kopiec(tab);
    readln;
end.
