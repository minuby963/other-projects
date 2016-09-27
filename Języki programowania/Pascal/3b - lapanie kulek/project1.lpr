program Project1;

uses graph, crt;

function update (polozenie:integer):integer;
var  przesuniecie:integer;
     znak:char;
begin
    przesuniecie:=10;
    writeln ('przed');
    if keypressed then
    begin
        znak:=ReadKey;
      if(znak='a') or (znak='d') then
      begin
          writeln ('po');
         {cleardevice; }
      end;
      if(znak='a') then
      begin
        if (polozenie>9) then
        begin
          polozenie:=polozenie-przesuniecie;
          {rectangle(polozenie, 450,polozenie+60, 460);}
          update:=polozenie;
        end
        else
        begin
           {rectangle(polozenie, 450,polozenie+60, 460);}
          update:=polozenie;
        end;
      end;
      if(znak='d') then
      begin
          if (polozenie<571) then
          begin
            polozenie:=polozenie+przesuniecie;
            {rectangle(polozenie, 450,polozenie+60, 460);}
            update:=polozenie;

          end
          else
          begin
            {rectangle(polozenie, 450,polozenie+60, 460);}
            update:=polozenie;
          end;
      end;
    end;
end;



var polozenie:integer;
  ster,tryb: smallint;
  game_end:integer;
  rand:integer;
begin
  {ster:=VGA;  tryb:=VGAHi;}
  game_end:=100;
  {InitGraph(ster, tryb, 'C:\Programs\lazarus\fpc\2.6.4\units\i386-win32\graph\graph.o');  }
  polozenie:=300;
  {circle(100,100,5);
  rectangle(polozenie, 450,polozenie+60, 460);  }
  randomize;
  rand:=random(10);

  repeat
    writeln(polozenie,'    ',polozenie+60);
    polozenie:=update(polozenie);
    {game_end:=game_end-1;}
  Until game_end=0;

end.
