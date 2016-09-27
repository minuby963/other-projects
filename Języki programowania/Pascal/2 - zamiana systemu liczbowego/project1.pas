program project1;

uses math;
var liczba: integer;
  sys: integer;
  na_sys: integer;
  a,b: integer;
  {pod: integer;}
  i: integer;
  wynik: integer;

function potega(pod:integer; i:integer): integer;
var b: integer;
  wynik: integer;
begin
  wynik:=1;
  {writeln('i2 = ',i);}
  if i>0 then
  begin
    for b:=0 to i-1 do
    begin
      wynik:=wynik*pod;
      {writeln('sprawdzenie');}
    end;
  end;
  {writeln('wynik = ',wynik); }
  potega:=wynik;
end;

function z_10(liczba:integer;na_sys:integer): integer;
var b: integer;
  wynik: integer;
  tab: array[0..31] of integer;
begin
  b:=0;
  while liczba>0 do
  begin
        tab[b] := liczba mod na_sys;
        {writeln('tab[b] = ',tab[b]);}
        liczba := liczba div na_sys;
        b:=b+1;
        {writeln('b = ',b);}
  end;
  while b<>0 do
  begin
        b:=b-1;
        {writeln('b2 = ',b);}
         write(tab[b]);
  end;
         writeln;
  wynik:=0;
  z_10:=wynik;
end;

begin
  writeln('podaj system w ktorym jest liczba');
  readln(sys);
  writeln('podaj liczbe');
  readln(liczba);
  writeln('podaj system na jaki zamienic liczbe');
  readln(na_sys);
  i:=0;
  wynik:= 0;
  if sys=10 then
  begin
     z_10 (liczba,na_sys);
  end
  else
  begin
    while i<10 do
    begin
      {writeln('i = ',i); }
       a:=liczba mod potega(10,i);
       if i=0 then
       begin
         a:=0;
       end;
       b:=(liczba mod potega(10,i+1)-a) div (potega(10,i));
       {writeln('a = ',a);}
       {writeln('b = ',b);}
       i:=i+1;
       wynik:=wynik+b*potega(sys,i-1);
       {writeln('potega: ',potega(sys,i-1));
       writeln('wynik: ',wynik);}
    end;
    if(na_sys=10) then
    begin
         writeln('w systemie dziesietnym: ',wynik);
    end
    else
    begin
       z_10 (wynik,na_sys);
    end;
  end;



  readln;
end.
