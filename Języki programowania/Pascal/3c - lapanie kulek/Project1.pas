program Project1;

uses graph, crt;

function update (polozenie:integer;y:integer;rand:integer):integer;
var  przesuniecie:integer;
     znak:char;
begin
    przesuniecie:=10;
    writeln ('przed');
    circle(rand,y,5);
    if keypressed then
    begin
        znak:=ReadKey;
        writeln('znak = ',znak);
      if(znak='a') or (znak='d') then
      begin
          writeln ('po');
          {cleardevice;}
      end;
      writeln('znak2 = ',znak);
      writeln('polozenie = ',polozenie);
      if(znak='a') then
      begin
        if (polozenie>9) then
        begin
          polozenie:=polozenie-przesuniecie;
          rectangle(polozenie, 450,polozenie+60, 460);
          update:=polozenie;
        end
        else
        begin
           rectangle(polozenie, 450,polozenie+60, 460);
          update:=polozenie;
        end;
      end;
      if(znak='d') then
      begin
          if (polozenie<571) then
          begin
            polozenie:=polozenie+przesuniecie;
            rectangle(polozenie, 450,polozenie+60, 460);
            update:=polozenie;

          end
          else
          begin
            rectangle(polozenie, 450,polozenie+60, 460);
            update:=polozenie;
          end;
      end;
    end;
    rectangle(polozenie, 450,polozenie+60, 460);
    update:=polozenie;
end;



var polozenie:integer;
  ster,tryb: smallint;
  game_end,game_end2:integer;
  rand:integer;
  y:integer;
  rpkt:string;
  rend:string;
  pkt:integer;
begin
  ster:=VGA;  tryb:=VGAHi;
  game_end:=200;
  game_end2:=5;
  pkt:=0;
  InitGraph(ster, tryb, 'C:\Programs\lazarus\fpc\2.6.4\units\i386-win32\graph\graph.o');
  polozenie:=300;
  {circle(100,100,5);}
  rectangle(polozenie, 450,polozenie+60, 460);
  randomize;
  readln;
  repeat
    rand:=random(628)+5;
    y:=0;
    repeat
      writeln(polozenie,'    ',polozenie+60);
      cleardevice;
      polozenie:=update(polozenie,y,rand);
     { outtextxy(10,10,'punkty: ');
      outtextxy(40,10,string(pkt));
      outtextxy(10,30,'zycia: ');
      }
      y:=y+4;
      delay(50);
      if (y>450)and(y<455) then
      begin
          if (polozenie<rand) and(rand<polozenie+60) then
          begin
              game_end:=1;
              pkt:=pkt+1;
          end
          else
          begin
              game_end2:=game_end-1;
              outtextxy(10,10,'adsasdasdasdasd ');
              game_end:=10;
          end;
      end;
      game_end:=game_end-1;
    Until game_end=0;
    game_end:=200 ;
  until game_end2=0;
  cleardevice;
  outtextxy(10,30,'KONIEC GRY');
  readln;
end.
