program Project1;

const ILOSC=10;
type tablica=array [1..ILOSC] of integer;
var tab:tablica;


procedure quicksort (poczatek,koniec:integer);
var podzial,swap,i,j:integer;
begin
  if (poczatek<koniec) then
  begin
    podzial:=tab[(koniec+poczatek) div 2];
    i:=poczatek-1;
    j:=koniec+1;


    repeat
      repeat i:=i+1 until (podzial<=tab[i]);
      repeat j:=j-1 until (podzial>=tab[j]);
      swap:=tab[i];
      tab[i]:=tab[j];
      tab[j]:=swap;
    until (i>=j);
    tab[j]:=tab[i];
    tab[i]:=swap;
    quicksort(poczatek,i-1);
    quicksort(i,koniec)
  end
end;


Procedure Quicksort2 (l,r:Integer);
Var
    pivot,b,i,j:Integer;
Begin
    If l < r Then
    Begin
        pivot := tab[random(r-l) + l+1];  { losowanie elementu dzielącego }
        //pivot:=t[(l+r) lsl 1];
        i := l-1;
        j := r+1;
        Repeat
            Repeat i := i+1 Until pivot <= tab[i];
            Repeat j := j-1 Until pivot >= tab[j];
            b:=tab[i]; tab[i]:=tab[j]; tab[j]:=b
        Until i >= j;
        tab[j]:=tab[i]; tab[i]:=b;
        Quicksort2(l,i-1);
        Quicksort2(i,r)
    End
End;

var i:integer;
begin
  randomize;
  for i:=1 to ILOSC do
  begin
    tab[i]:=(random(567) mod 20);
    write(tab[i],', ');

  end;
  writeln;
  Quicksort2(1,ILOSC);
  for i:=1 to ILOSC do
  begin
    write(tab[i],', ');
  end;
  writeln;
  quicksort(1,ILOSC);
  for i:=1 to ILOSC do
  begin
    write(tab[i],', ');
  end;

  readln;
end.
