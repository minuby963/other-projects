program Project1;

type PtrList=^list;
     list=record
       prev:PtrList;
       liczba:char;
       next:PtrList;
     end;

var poczatek, koniec:PtrList;


procedure dodaj_pocz(znak:char);
var tmp:PtrList;
begin
  new(tmp);

  tmp^.liczba:=znak;
  tmp^.next:=poczatek;

  if(poczatek<>NIL) then
  begin
    tmp^.next^.prev:=tmp;
  end;

  if(poczatek=NIL) then
  begin
    koniec:=tmp;
  end;
  poczatek:=tmp;
  tmp^.prev:=NIL;

end;

procedure dodaj_kon (znak:char);
var tmp:PtrList;
begin
  new(tmp);
  tmp^.liczba:=znak;
  tmp^.prev:=koniec;
  tmp^.next:=NIl;
  koniec^.next:=tmp;
  koniec:=tmp;

end;

procedure wyswietl1 (poczatek:PtrList);
var tmp:PtrList;
begin
  tmp:=poczatek;
  while(tmp<>NIL) do
  begin
    writeln(tmp^.liczba);
    tmp:=tmp^.next;
  end;
end;

procedure wyswietl2 (koniec:PtrList);
var tmp:PtrList;
begin
  tmp:=koniec;
  while(tmp<>NIL) do
  begin
    writeln(tmp^.liczba);
    tmp:=tmp^.prev;
  end;
end;

var znak:char;
begin
  while (true) do
  begin
    write('podaj liczbe: ');
    readln(znak);
    if(znak='.') then break;
    dodaj_pocz(znak);
  end;
  write('podaj liczbe: ');
  readln(znak);
  dodaj_kon(znak);

  writeln('od poczatku: ');
  wyswietl1(poczatek);
  writeln('od konca: ');
  wyswietl2(koniec);
  readln;
end.
