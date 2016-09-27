PROGRAM Snake;

USES
  allegro, sysutils, crt, DOS;

VAR
  bufor:pointer;

CONST
  ILOSC = 3;
  MAX = 4000;

TYPE
  tablica = array [0..ILOSC,0..MAX] of integer;

procedure inicjalizacja;
begin
  if not al_init then
  begin
    WriteLn ('Nie udalo sie zainicjalizowac allegro');
    EXIT;
  end;

  al_install_keyboard;
  al_install_timer;
  al_install_sound(AL_DIGI_AUTODETECT, AL_MIDI_AUTODETECT);
  al_set_color_depth(32);
  al_set_window_title('SNAKE');

  if not al_set_gfx_mode (AL_GFX_SAFE, 800, 600, 0, 0) then
  begin
    al_message ('Nie udalo sie zainicjalizowac allegro okna graficznego');
    al_exit;
    EXIT;
  end;
end;

procedure waz_na_poczatku(var pozx,pozy:tablica);
var i,j:integer;
begin
  for j:=0 to 62 do
  begin
    for i:=0 to ILOSC do
    begin
      pozx[i][j]:=j*13-16;
      pozy[i][j]:=13;
    end;
  end;
  for j:=63 to 106 do
  begin
    for i:=0 to ILOSC do
    begin
      pozx[i][j]:=790;
      pozy[i][j]:=(j-61)*13;
    end;
  end;
  for j:=107 to 166 do
  begin
    for i:=0 to ILOSC do
    begin
      pozx[i][j]:=790-(j-106)*13;
      pozy[i][j]:=585;
    end;
  end;
  for j:=167 to 208 do
  begin
    for i:=0 to ILOSC do
    begin
      pozx[i][j]:=10;
      pozy[i][j]:=585-13*(j-166);
    end;
  end;
  for j:=209 to 266 do
  begin
    for i:=0 to ILOSC do
    begin
      pozx[i][j]:=10+13*(j-208);
      pozy[i][j]:=39;
    end;
  end;
  for j:=267 to 306 do
  begin
    for i:=0 to ILOSC do
    begin
      pozx[i][j]:=764;
      pozy[i][j]:=39+13*(j-266);
    end;
  end;
  for j:=307 to 362 do
  begin
    for i:=0 to ILOSC do
    begin
      pozx[i][j]:=764-13*(j-306);
      pozy[i][j]:=559;
    end;
  end;
  for j:=363 to 400 do
  begin
    for i:=0 to ILOSC do
    begin
      pozx[i][j]:=36;
      pozy[i][j]:=559-13*(j-362);
    end;
  end;
  for j:=401 to 454 do
  begin
    for i:=0 to ILOSC do
    begin
      pozx[i][j]:=36+13*(j-400);
      pozy[i][j]:=65;
    end;
  end;
  for j:=455 to 490 do
  begin
    for i:=0 to ILOSC do
    begin
      pozx[i][j]:=738;
      pozy[i][j]:=65+13*(j-454);
    end;
  end;
  for j:=491 to 542 do
  begin
    for i:=0 to ILOSC do
    begin
      pozx[i][j]:=738-13*(j-490);
      pozy[i][j]:=533;
    end;
  end;
  for j:=543 to 576 do
  begin
    for i:=0 to ILOSC do
    begin
      pozx[i][j]:=62;
      pozy[i][j]:=533-13*(j-542);
    end;
  end;
  for j:=577 to 626 do
  begin
    for i:=0 to ILOSC do
    begin
      pozx[i][j]:=62+13*(j-576);
      pozy[i][j]:=91;
    end;
  end;
  for j:=627 to 658 do
  begin
    for i:=0 to ILOSC do
    begin
      pozx[i][j]:=712;
      pozy[i][j]:=91+13*(j-626);
    end;
  end;
  for j:=659 to 706 do
  begin
    for i:=0 to ILOSC do
    begin
      pozx[i][j]:=712-13*(j-658);
      pozy[i][j]:=507;
    end;
  end;
  for j:=707 to 736 do
  begin
    for i:=0 to ILOSC do
    begin
      pozx[i][j]:=88;
      pozy[i][j]:=507-13*(j-706);
    end;
  end;
  for j:=737 to 782 do
  begin
    for i:=0 to ILOSC do
    begin
      pozx[i][j]:=88+13*(j-736);
      pozy[i][j]:=117;
    end;
  end;
  for j:=783 to 810 do
  begin
    for i:=0 to ILOSC do
    begin
      pozx[i][j]:=686;
      pozy[i][j]:=117+13*(j-782);
    end;
  end;
  for j:=811 to 854 do
  begin
    for i:=0 to ILOSC do
    begin
      pozx[i][j]:=686-13*(j-810);
      pozy[i][j]:=481;
    end;
  end;
  for j:=855 to 880 do
  begin
    for i:=0 to ILOSC do
    begin
      pozx[i][j]:=114;
      pozy[i][j]:=481-13*(j-854);
    end;
  end;
  for j:=881 to 900 do
  begin
    for i:=0 to ILOSC do
    begin
      pozx[i][j]:=114+13*(j-880);
      pozy[i][j]:=143;
    end;
  end;
  for j:=901 to 903 do
  begin
    for i:=0 to ILOSC do
    begin
      pozx[i][j]:=374;
      pozy[i][j]:=143+13*(j-900);
    end;
  end;
end;

procedure buforuj_poziom (poziom:integer);
begin
  if poziom=2 then
  begin
    al_rectfill(bufor, 195, 100, 205, 500, al_makecol(24,0,24));
    al_rectfill(bufor, 595, 100, 605, 500, al_makecol(24,0,24));
  end;
  if poziom=3 then
  begin
    al_rectfill(bufor, 95, 100, 105, 500, al_makecol(24,0,24));
    al_rectfill(bufor, 695, 100, 705, 500, al_makecol(24,0,24));
    al_rectfill(bufor, 95, 100, 705, 110, al_makecol(24,0,24));

    al_rectfill(bufor, 195, 200, 205, 500, al_makecol(24,0,24));
    al_rectfill(bufor, 595, 200, 605, 500, al_makecol(24,0,24));
    al_rectfill(bufor, 195, 490, 605, 500, al_makecol(24,0,24));
  end;
  if poziom=4 then
  begin
    al_rectfill(bufor, 95, 100, 105, 500, al_makecol(24,0,24));
    al_rectfill(bufor, 695, 100, 705, 500, al_makecol(24,0,24));
    al_rectfill(bufor, 95, 100, 705, 110, al_makecol(24,0,24));
    al_rectfill(bufor, 95, 490, 605, 500, al_makecol(24,0,24));

    al_rectfill(bufor, 195, 200, 205, 400, al_makecol(24,0,24));
    al_rectfill(bufor, 595, 200, 605, 400, al_makecol(24,0,24));
    al_rectfill(bufor, 295, 200, 605, 210, al_makecol(24,0,24));
    al_rectfill(bufor, 195, 390, 605, 400, al_makecol(24,0,24));
  end;
end;

procedure sciany(poziom:integer);
begin
  al_rectfill(bufor, 0, 0, 10, 600, al_makecol(24,0,24));
  al_rectfill(bufor, 0, 0, 800, 10, al_makecol(24,0,24));
  al_rectfill(bufor, 790, 0, 800, 600, al_makecol(24,0,24));
  al_rectfill(bufor, 10, 590, 800, 600, al_makecol(24,0,24));
  if (poziom>1) then
  begin
    buforuj_poziom (poziom);
  end;
end;

procedure buforuj_zycia_pkt_predkosc_poziom(zycia,pkt,predkosc,poziom:integer);
var strzycia:string;
    strpkt:string;
    strpredkosc:string;
    strpoziom:string;
begin
  predkosc:=30-predkosc+1;
  str (zycia:2,strzycia);
  al_textout_ex(bufor, al_font, 'zycia: '+strzycia, 20, 20, al_makecol(128, 0, 128), -1);
  str (pkt:2,strpkt);
  al_textout_ex(bufor, al_font, 'punkty:'+strpkt, 20, 30, al_makecol(128, 0, 128), -1);
  str (poziom:2,strpoziom);
  al_textout_ex(bufor, al_font, 'poziom:  '+strpoziom, 690, 20, al_makecol(128, 0, 128), -1);
  str (predkosc:2,strpredkosc);
  al_textout_ex(bufor, al_font, 'predkosc:'+strpredkosc, 690, 30, al_makecol(128, 0, 128), -1);
end;

procedure rysuj(iteracja:integer;var przechodzenie,i,j,czas_migotania,poziom:integer);
begin
  al_clear_to_color(bufor, al_makecol(64,0,64));
  if(przechodzenie=0) then
  begin
  sciany(poziom);
  end
  else
  begin
    if(((iteracja mod 20)=0) or (i=1))then
    begin
      sciany(poziom);
      i:=1;
      j:=j+1;
      if (j>10) then
      begin
        i:=0;
        j:=0;
        czas_migotania:=czas_migotania+1;
      end;
      if(czas_migotania>20) then
      begin
        przechodzenie:=0;
        czas_migotania:=0;
      end;
    end;
  end;
end;

procedure menu(var koniec_gry:integer);
var key:integer;
begin
  key:=0;
    while key<>17165 do
    begin
        key:=al_readkey;
        if key=15131 then
        begin
          koniec_gry:=0;
          break;
        end;
    end;
end;

procedure menu_odjac_zycie();
begin
  al_rectfill(al_screen, 200, 200, 600, 370, al_makecol(50,0,50));
  al_rectfill(al_screen, 210, 210, 590, 360, al_makecol(24,0,24));
  al_textout_ex(al_screen, al_font, 'WCISNIJ ENTER ABY WZNOWIC GRE', 285, 280, al_makecol(128, 0, 128), -1);
end;

procedure menu_kolejny_poziom(poziom,koniec_gry:integer);
var strpoziom:string;
begin
  str (poziom:2,strpoziom);
  al_rectfill(al_screen, 200, 200, 600, 370, al_makecol(50,0,50));
  al_rectfill(al_screen, 210, 210, 590, 360, al_makecol(24,0,24));
  al_textout_ex(al_screen, al_font, 'POZIOM'+strpoziom, 375, 278, al_makecol(128, 0, 128), -1);
  al_textout_ex(al_screen, al_font, 'WCISNIJ ENTER ABY KONTYNUOWAC GRE', 285, 290, al_makecol(128, 0, 128), -1);
  menu(koniec_gry);
end;

procedure menu_koniec_gry(var koniec_gry:integer;pkt:integer);
var strpkt:string;
begin
  str (pkt:2,strpkt);
  al_rectfill(al_screen, 200, 200, 580, 370, al_makecol(50,0,50));
  al_rectfill(al_screen, 210, 210, 570, 360, al_makecol(24,0,24));
  al_textout_ex(al_screen, al_font, 'KONIEC GRY!!!', 335, 278, al_makecol(128, 0, 128), -1);
  al_textout_ex(al_screen, al_font, 'TWOJ WYNIK TO:'+strpkt, 325, 290, al_makecol(128, 0, 128), -1);
  koniec_gry:=0;
end;

procedure odjac_zycie_poziom(var zycia,poziom,pozx1,pozy1,koniec_gry,pkt:integer;var pozx,pozy:tablica;przechodzenie:integer);
var i,j:integer;
begin
  if(przechodzenie=0) then
  begin
    if poziom=2 then
    begin
      if ((pozx1>185) and (pozx1<215)) and ((pozy1>90) and (pozy1<510)) then
      begin
        zycia:=zycia-1;
        pozx1:=400;
        pozy1:=300;
        for j:=0 to MAX do
        begin
          for i:=0 to ILOSC do
          begin
            pozx[i][j]:=-10;
            pozy[i][j]:=-10;
          end;
        end;
        if (zycia <> -1) then
        begin
          menu_odjac_zycie();
        end
        else
        begin
          menu_koniec_gry(koniec_gry,pkt);
        end;
        menu(koniec_gry);
      end;
      if ((pozx1>585) and (pozx1<615)) and ((pozy1>90) and (pozy1<510)) then
      begin
        zycia:=zycia-1;
        pozx1:=400;
        pozy1:=300;
        for j:=0 to MAX do
        begin
          for i:=0 to ILOSC do
          begin
            pozx[i][j]:=-10;
            pozy[i][j]:=-10;
          end;
        end;
        if (zycia <> -1) then
        begin
          menu_odjac_zycie();
        end
        else
        begin
          menu_koniec_gry(koniec_gry,pkt);
        end;
        menu(koniec_gry);
      end;
    end;

    if poziom = 3 then
    begin
      if (((pozx1>85) and (pozx1<115)) and ((pozy1>90) and (pozy1<510))) or (((pozx1>685) and (pozx1<715)) and ((pozy1>90) and (pozy1<510))) or (((pozx1>85) and (pozx1<685)) and ((pozy1>90) and (pozy1<120))) then
      begin
        zycia:=zycia-1;
        pozx1:=400;
        pozy1:=300;
        for j:=0 to MAX do
        begin
          for i:=0 to ILOSC do
          begin
            pozx[i][j]:=-10;
            pozy[i][j]:=-10;
          end;
        end;
        if (zycia <> -1) then
        begin
          menu_odjac_zycie();
        end
        else
        begin
          menu_koniec_gry(koniec_gry,pkt);
        end;
        menu(koniec_gry);
      end;
      if (((pozx1>185) and (pozx1<215)) and ((pozy1>190) and (pozy1<510))) or (((pozx1>585) and (pozx1<615)) and ((pozy1>190) and (pozy1<510))) or (((pozx1>185) and (pozx1<615)) and ((pozy1>480) and (pozy1<510))) then
      begin
        zycia:=zycia-1;
        pozx1:=400;
        pozy1:=300;
        for j:=0 to MAX do
        begin
          for i:=0 to ILOSC do
          begin
            pozx[i][j]:=-10;
            pozy[i][j]:=-10;
          end;
        end;
        if (zycia <> -1) then
        begin
          menu_odjac_zycie();
        end
        else
        begin
          menu_koniec_gry(koniec_gry,pkt);
        end;
        menu(koniec_gry);
      end;
    end;
    if poziom = 4 then
    begin
      if (((pozx1>85) and (pozx1<115)) and ((pozy1>90) and (pozy1<510))) or (((pozx1>685) and (pozx1<715)) and ((pozy1>90) and (pozy1<510))) or (((pozx1>85) and (pozx1<715)) and ((pozy1>90) and (pozy1<120))) or (((pozx1>85) and (pozx1<615)) and ((pozy1>480) and (pozy1<510))) then
      begin
        zycia:=zycia-1;
        pozx1:=400;
        pozy1:=300;
        for j:=0 to MAX do
        begin
          for i:=0 to ILOSC do
          begin
            pozx[i][j]:=-10;
            pozy[i][j]:=-10;
          end;
        end;
        if (zycia <> -1) then
        begin
          menu_odjac_zycie();
        end
        else
        begin
          menu_koniec_gry(koniec_gry,pkt);
        end;
        menu(koniec_gry);
      end;
      if (((pozx1>185) and (pozx1<215)) and ((pozy1>190) and (pozy1<410))) or (((pozx1>585) and (pozx1<615)) and ((pozy1>190) and (pozy1<410))) or (((pozx1>285) and (pozx1<615)) and ((pozy1>190) and (pozy1<220))) or (((pozx1>185) and (pozx1<615)) and ((pozy1>380) and (pozy1<410))) then
      begin
        zycia:=zycia-1;
        pozx1:=400;
        pozy1:=300;
        for j:=0 to MAX do
        begin
          for i:=0 to ILOSC do
          begin
            pozx[i][j]:=-10;
            pozy[i][j]:=-10;
          end;
        end;
        if (zycia <> -1) then
        begin
          menu_odjac_zycie();
        end
        else
        begin
          menu_koniec_gry(koniec_gry,pkt);
        end;
        menu(koniec_gry);
      end;
    end;
  end;
end;

procedure odjac_zycie (var pozx1,pozy1,koniec_gry,zycia,pkt:integer;var pozx,pozy:tablica;przechodzenie,poziom:integer);
var i,j,p:integer;
begin
  if(przechodzenie=0) then
  begin
    if ((pozx1<20) or (pozx1>780) or (pozy1<20) or (pozy1>580)) then
    begin
      zycia:=zycia-1;
      pozx1:=400;
      pozy1:=300;
      for j:=0 to MAX do
      begin
        for i:=0 to ILOSC do
        begin
          pozx[i][j]:=-10;
          pozy[i][j]:=-10;
        end;
      end;
      if (zycia <> -1) then
      begin
        menu_odjac_zycie();
      end
      else
      begin
        menu_koniec_gry(koniec_gry,pkt);
      end;
      menu(koniec_gry);
    end;
  end;
    p:=pkt;
    while (p>0) do
    begin
        if (pozx[3][p]-pozx1<9) and (pozx1-pozx[3][p]<9) then
        begin
          if (pozy[3][p]-pozy1<9) and (pozy1-pozy[3][p]<9) then
          begin
            zycia:=zycia-1;
            pozx1:=400;
            pozy1:=300;
            for j:=0 to MAX do
            begin
              for i:=0 to ILOSC do
              begin
                pozx[i][j]:=-10;
                pozy[i][j]:=-10;
              end;
            end;
            if (zycia <> -1) then
            begin
              menu_odjac_zycie();
            end
            else
            begin
              menu_koniec_gry(koniec_gry,pkt);
            end;
            menu(koniec_gry);
          end;
        end;
        p:=p-1;
    end;
    odjac_zycie_poziom(zycia,poziom,pozx1,pozy1,koniec_gry,pkt,pozx,pozy,przechodzenie);
    if(zycia=-1) then
    begin
      koniec_gry:=0;
    end;
end;

procedure sprawdz_pozycje (var klawisz2,pozx1,pozy1,koniec_gry,kroki:integer);
var klawisz,i:integer;
begin
  if al_keypressed then
    begin
      klawisz:=al_readkey;
      if ((klawisz2<>21248) and (klawisz=20992)) then
      begin
        pozx1:=pozx1-kroki;
        klawisz2:=klawisz;
      end;
      if ((klawisz2<>20992) and (klawisz=21248)) then
      begin
        pozx1:=pozx1+kroki;
        klawisz2:=klawisz;
      end;
      if ((klawisz2<>21760) and (klawisz=21504)) then
      begin
        pozy1:=pozy1-kroki;
        klawisz2:=klawisz;
      end;
      if ((klawisz2<>21504) and (klawisz=21760)) then
      begin
        pozy1:=pozy1+kroki;
        klawisz2:=klawisz;
      end;
      if klawisz=15131 then koniec_gry:=0;
    end;
    if klawisz2=20992 then pozx1:=pozx1-kroki;
    if klawisz2=21248 then pozx1:=pozx1+kroki;
    if klawisz2=21504 then pozy1:=pozy1-kroki;
    if klawisz2=21760 then pozy1:=pozy1+kroki;
    for i:=0 to 8 do
    begin
      if pozx1=-i then pozx1:=799-i;
      if pozy1=-i then pozy1:=599-i;
      if pozx1=800+i then pozx1:=1+i;
      if pozy1=600+i then pozy1:=1+i;
    end;
end;

procedure buforuj_pozycje (pozx1,pozy1,klawisz2:integer);
var kierunekx1,kieruneky1,kierunekx2,kieruneky2:integer;
begin
    kierunekx1:=-2;
    kierunekx2:=2;
    kieruneky1:=-2;
    kieruneky2:=-2;
    al_circlefill(bufor, pozx1, pozy1,10, al_makecol(0,128,0));
    if klawisz2=20992 then
    begin
      kierunekx1:=-2;
      kierunekx2:=-2;
      kieruneky1:=2;
      kieruneky2:=-2;
    end;
    if klawisz2=21248 then
    begin
      kierunekx1:=2;
      kierunekx2:=2;
      kieruneky1:=2;
      kieruneky2:=-2;
    end;
    if klawisz2=21504 then
    begin
      kierunekx1:=-2;
      kierunekx2:=2;
      kieruneky1:=-2;
      kieruneky2:=-2;
    end;
    if klawisz2=21760 then
    begin
      kierunekx1:=-2;
      kierunekx2:=2;
      kieruneky1:=2;
      kieruneky2:=2;
    end;
    al_circlefill(bufor, pozx1+kierunekx1, pozy1+kieruneky1,2, al_makecol(0,0,0));
    al_circlefill(bufor, pozx1+kierunekx2, pozy1+kieruneky2,2, al_makecol(0,0,0));
end;

procedure buforuj_nast_kulke(pkt:integer; pozx,pozy:tablica);
var i:integer;
begin
    i:=pkt;
    while (i>0) do
    begin
        al_circlefill(bufor, pozx[2][i], pozy[2][i],8, al_makecol(0,128,0));
        al_circlefill(bufor, pozx[3][i], pozy[3][i],8, al_makecol(0,128,0));
        al_circlefill(bufor, pozx[3][i], pozy[3][i],6, al_makecol(0,140,0));
        i:=i-1;
    end;
end;

procedure dodaj_nast_kulke (var pozx,pozy:tablica; pkt,pozx1,pozy1:integer);
var i,j:integer;
begin
    i:=pkt;
    pozx[ILOSC][0]:=pozx1;
    pozy[ILOSC][0]:=pozy1;
    while (i>=1) do
    begin
        j:=ILOSC;
        while (j>=1) do
        begin
            pozx[j][i]:=pozx[j-1][i];
            pozy[j][i]:=pozy[j-1][i];
            j:=j-1;
        end;
        pozx[0][i]:=pozx[ILOSC][i-1];
        pozy[0][i]:=pozy[ILOSC][i-1];
        i:=i-1;
    end;
end;

procedure punkty(var pozx2,pozy2,pkt:integer; pozx,pozy:tablica);
var p:integer;
begin
  p:=pkt;
  pozx2:=18+(random(1452) mod 765);
  pozy2:=18+(random(2387) mod 565);
  if ((pkt-19>=0) and (pkt-19<=21)) and (((pozx2>175) and (pozx2<225) and (pozy2>80) and (pozy2<520)) or ((pozx2>575) and (pozx2<625) and (pozy2>80) and (pozy2<520))) then
  begin
    punkty(pozx2,pozy2,pkt,pozx,pozy);
  end;
  if ((pkt-39>=0) and (pkt-39<=21)) and (((((pozx2>85) and (pozx2<115)) and ((pozy2>90) and (pozy2<510))) or (((pozx2>685) and (pozx2<715)) and ((pozy2>90) and (pozy2<510))) or (((pozx2>85) and (pozx2<685)) and ((pozy2>90) and (pozy2<120)))) or ((((pozx2>185) and (pozx2<215)) and ((pozy2>190) and (pozy2<510))) or (((pozx2>585) and (pozx2<615)) and ((pozy2>190) and (pozy2<510))) or (((pozx2>185) and (pozx2<615)) and ((pozy2>480) and (pozy2<510))))) then
  begin
    punkty(pozx2,pozy2,pkt,pozx,pozy);
  end;
  if ((pkt-59>=0) and (pkt-59<=21)) and (((((pozx2>85) and (pozx2<115)) and ((pozy2>90) and (pozy2<510))) or (((pozx2>685) and (pozx2<715)) and ((pozy2>90) and (pozy2<510))) or (((pozx2>85) and (pozx2<715)) and ((pozy2>90) and (pozy2<120))) or (((pozx2>85) and (pozx2<615)) and ((pozy2>480) and (pozy2<510)))) or ((((pozx2>185) and (pozx2<215)) and ((pozy2>190) and (pozy2<410))) or (((pozx2>585) and (pozx2<615)) and ((pozy2>190) and (pozy2<410))) or (((pozx2>285) and (pozx2<615)) and ((pozy2>190) and (pozy2<220))) or (((pozx2>185) and (pozx2<615)) and ((pozy2>380) and (pozy2<410))))) then
  begin
    punkty(pozx2,pozy2,pkt,pozx,pozy);
  end;
  while (p>0) do
  begin
    if (pozx[ILOSC][p]-pozx2<10) and (pozx2-pozx[ILOSC][p]<10) then
    begin
      if (pozy[ILOSC][p]-pozy2<10) and (pozy2-pozy[ILOSC][p]<10) then
      begin
        punkty(pozx2,pozy2,pkt,pozx,pozy);
      end;
    end;
    p:=p-1;
  end;
end;

procedure buforuj_pkt (pozx2, pozy2, pkt:integer);
begin
  if ((pkt+1) mod 20)=0 then
  begin
    al_circlefill(bufor, pozx2, pozy2,7, al_makecol(0,255,0));
    al_circlefill(bufor, pozx2, pozy2,4, al_makecol(0,170,0));
  end
  else
  begin
    al_circlefill(bufor, pozx2, pozy2,7, al_makecol(255,255,0));
    al_circlefill(bufor, pozx2, pozy2,4, al_makecol(170,170,0));
  end;
end;

procedure buforuj_pkt_przechodzenia (pozx3, pozy3:integer);
begin
    al_circlefill(bufor, pozx3, pozy3,7, al_makecol(255,25,0));
    al_circlefill(bufor, pozx3, pozy3,4, al_makecol(170,17,0));
end;

procedure sprawdz_pkt(var pozx1,pozy1,pozx2,pozy2,pkt:integer; pozx,pozy:tablica);
begin
    if ((pozx1-pozx2<13) and (pozx2-pozx1<13)) then
    begin
        if ((pozy1-pozy2<13) and (pozy2-pozy1<13)) then
        begin
            pkt:=pkt+1;
            punkty(pozx2,pozy2,pkt,pozx,pozy);
        end;
    end;
end;

procedure zwieksz_szybkosc(var pkt,pkt2,predkosc:integer);
begin
    if predkosc>=0 then
    begin
      if (pkt<>pkt2) then
      begin
        if ((pkt mod 2)=0) then
        begin
          predkosc:=predkosc-1;
        end;
        pkt2:=pkt;
      end;
    end;
end;

procedure gen_pkt_przechodzenia(iteracje,pkt:integer; var pozx3,pozy3:integer;pozx,pozy:tablica);
var los,los2,p:integer;
begin
   p:=pkt;
   los:=(random (1456) mod 400)+150;
   los2:=(random (1730) mod 1000)+700;
   if ((iteracje mod los)=0) then
   begin
     pozx3:=18+(random(452) mod 765);
     pozy3:=18+(random(387) mod 565);
     if ((pkt-19>=0) and (pkt-19<=21)) and (((pozx3>175) and (pozx3<225) and (pozy3>80) and (pozy3<520)) or ((pozx3>575) and (pozx3<625) and (pozy3>80) and (pozy3<520))) then
     begin
       pozx3:=-10;
       pozx3:=-10;
     end;
     if ((pkt-39>=0) and (pkt-39<=21)) and (((((pozx3>85) and (pozx3<115)) and ((pozy3>90) and (pozy3<510))) or (((pozx3>685) and (pozx3<715)) and ((pozy3>90) and (pozy3<510))) or (((pozx3>85) and (pozx3<685)) and ((pozy3>90) and (pozy3<120)))) or ((((pozx3>185) and (pozx3<215)) and ((pozy3>190) and (pozy3<510))) or (((pozx3>585) and (pozx3<615)) and ((pozy3>190) and (pozy3<510))) or (((pozx3>185) and (pozx3<615)) and ((pozy3>480) and (pozy3<510))))) then
      begin
         pozx3:=-10;
         pozx3:=-10;
      end;
      if ((pkt-59>=0) and (pkt-59<=21)) and (((((pozx3>85) and (pozx3<115)) and ((pozy3>90) and (pozy3<510))) or (((pozx3>685) and (pozx3<715)) and ((pozy3>90) and (pozy3<510))) or (((pozx3>85) and (pozx3<715)) and ((pozy3>90) and (pozy3<120))) or (((pozx3>85) and (pozx3<615)) and ((pozy3>480) and (pozy3<510)))) or ((((pozx3>185) and (pozx3<215)) and ((pozy3>190) and (pozy3<410))) or (((pozx3>585) and (pozx3<615)) and ((pozy3>190) and (pozy3<410))) or (((pozx3>285) and (pozx3<615)) and ((pozy3>190) and (pozy3<220))) or (((pozx3>185) and (pozx3<615)) and ((pozy3>380) and (pozy3<410))))) then
      begin
         pozx3:=-10;
         pozx3:=-10;
      end;
     while (p>0) do
     begin
       if (pozx[ILOSC][p]-pozx3<10) and (pozx3-pozx[ILOSC][p]<10) then
       begin
         if (pozy[ILOSC][p]-pozy3<10) and (pozy3-pozy[ILOSC][p]<10) then
         begin
           pozx3:=-10;
           pozy3:=-10;
         end;
       end;
       p:=p-1;
     end;
   end;
   if ((iteracje mod los2)=0) then
   begin
     pozx3:=-10;
     pozy3:=-10;
   end;
end;

procedure sprawdz_pkt_przechodzenia(var pozx3,pozy3,przechodzenie,czas_migotania:integer;pozx1,pozy1:integer);
begin
  if ((pozx1-pozx3<13) and (pozx3-pozx1<13)) then
    begin
        if ((pozy1-pozy3<13) and (pozy3-pozy1<13)) then
        begin
            pozx3:=-10;
            pozy3:=-10;
            przechodzenie:=1;
            czas_migotania:=0;
        end;
    end;
end;

procedure zmien_poziom (var poziom,pkt3,koniec_gry,predkosc,przechodzenie:integer;pkt:integer);
begin
  if (pkt<>pkt3) then
  begin
    if (pkt>0) and ((pkt mod 20)=0) then
    begin
      poziom:=poziom+1;
      przechodzenie:=1;
      predkosc:=30-6*poziom;
      if(predkosc<=0) then
      begin
        predkosc:=1;
      end;
      menu_kolejny_poziom(poziom,koniec_gry);
    end;
    pkt3:=pkt;
  end;
end;

var koniec_gry:integer;
    klawisz2:integer;
    pozx1,pozy1:integer;
    pozx2,pozy2:integer;
    pozx3,pozy3:integer;
    zycia:integer;
    pkt,pkt2,pkt3:integer;
    pozx,pozy:tablica;
    i,j:integer;
    kroki:integer;
    predkosc:integer;
    godz,min,sek,sek100:word;
    stoper,stoper1,stoper2,liczba:LongInt;
    poziom:integer;
    iteracje,przechodzenie,czas_migotania:integer;

BEGIN
  inicjalizacja;
  koniec_gry:=1;
  kroki:=4;
  predkosc:=30;
  pozx1:=400;
  pozy1:=300;
  klawisz2:=0;
  zycia:=5;
  pozx2:=0;
  pozy2:=0;
  pozx3:=-10;
  pozy3:=-10;
  pkt:=903;
  pkt2:=0;
  pkt3:=0;
  liczba:=1;
  godz:=0;
  min:=0;
  sek:=0;
  sek100:=0;
  poziom:=1;
  iteracje:=0;
  przechodzenie:=0;
  czas_migotania:=0;
  for j:=0 to MAX do
  begin
    for i:=0 to ILOSC do
    begin
      pozx[i][j]:=-10;
      pozy[i][j]:=-10;
    end;
  end;
  waz_na_poczatku(pozx,pozy);

  bufor:=NIL;
  bufor:=al_create_bitmap(800,600);
  if bufor = NIL then
  begin
    al_message('nie mogę załadować bufora');
    al_exit();
  end;

  randomize;
  punkty(pozx2,pozy2,pkt,pozx,pozy);

  al_clear_to_color(bufor, al_makecol(64,0,64));
  al_rectfill(bufor, 200, 200, 600, 370, al_makecol(50,0,50));
  al_rectfill(bufor, 210, 210, 590, 360, al_makecol(24,0,24));
  buforuj_nast_kulke(pkt,pozx,pozy);
  al_circlefill(bufor, 374-2, 182+2,2, al_makecol(0,0,0));
  al_circlefill(bufor, 374+2, 182+2,2, al_makecol(0,0,0));
  al_textout_ex(bufor, al_font, 'WCISNIJ ENTER ABY ROZPOCZAC GRE', 275, 278, al_makecol(128, 0, 128), -1);
  al_textout_ex(bufor, al_font, 'WCISNIJ ESC ABY ZAKONCZYC GRE', 282, 290, al_makecol(128, 0, 128), -1);
  al_blit(bufor,al_screen,0,0,0,0,800,600);
  menu(koniec_gry);
  for j:=0 to MAX do
  begin
    for i:=0 to ILOSC do
    begin
      pozx[i][j]:=-10;
      pozy[i][j]:=-10;
    end;
  end;
  pkt:=0;
  i:=0;
  while (koniec_gry>0) do
  begin

    GetTime(godz,min,sek,sek100);
    iteracje:=iteracje+1;
    if(iteracje>=1000) then iteracje:=0;
    stoper1:= ((godz*60+min*liczba)*60+sek*liczba)*100+sek100*liczba;
    sprawdz_pkt(pozx1,pozy1,pozx2,pozy2,pkt,pozx,pozy);
    odjac_zycie (pozx1,pozy1,koniec_gry,zycia,pkt,pozx,pozy,przechodzenie,poziom);
    dodaj_nast_kulke(pozx,pozy,pkt,pozx1,pozy1);
    sprawdz_pozycje (klawisz2,pozx1,pozy1,koniec_gry,kroki);
    zwieksz_szybkosc (pkt,pkt2,predkosc);
    zmien_poziom (poziom,pkt3,koniec_gry,predkosc,przechodzenie,pkt);
    gen_pkt_przechodzenia(iteracje,pkt,pozx3,pozy3,pozx,pozy);
    sprawdz_pkt_przechodzenia(pozx3,pozy3,przechodzenie,czas_migotania,pozx1,pozy1);

    rysuj(iteracje,przechodzenie,i,j,czas_migotania,poziom);
    buforuj_pkt (pozx2,pozy2,pkt);
    buforuj_pkt_przechodzenia (pozx3,pozy3);
    buforuj_nast_kulke(pkt,pozx,pozy);
    buforuj_pozycje (pozx1,pozy1,klawisz2);
    buforuj_zycia_pkt_predkosc_poziom(zycia,pkt,predkosc,poziom);
    GetTime(godz,min,sek,sek100);
    stoper2:= ((godz*60+min*liczba)*60+sek*liczba)*100+sek100*liczba;
    stoper:=stoper2-stoper1;

      if(predkosc-stoper>0) then
    begin
      al_rest(predkosc-stoper);
    end
    else
    begin
      al_rest(0);
    end;
    al_blit(bufor,al_screen,0,0,0,0,800,600);
  end;
  al_keypressed;
  al_destroy_bitmap(bufor);
  al_exit;
END.
