program Project1;

procedure wsk (var a:integer);
begin
  a:=1;
end;


var a:integer;

begin
  a:=2;
  writeln('a = ',a);
  wsk(a);
  writeln('a2 = ',a);
  readln;
end.
