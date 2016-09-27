program project1;

var x: integer;
y: integer;
a: integer;

begin
	a := 0;
	writeln('x = ');
	readln(x);
	writeln('y = ');
	readln(y);
	if y<0 then
	begin
		a:=a+2;
	end
	else
	begin
		a:=0;
	end;
	if x*y>0 then
	begin
		a:=a+1;
	end
	else
	begin
		a:=a+2
	end;
	writeln('cw ',a);
	readln;
end.

