PROGRAM timers3;

USES
  allegro, sysutils;

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
  al_set_window_title('WEGORZEL');

  if not al_set_gfx_mode (AL_GFX_SAFE, 800, 600, 0, 0) then
  begin
    al_message ('Nie udalo sie zainicjalizowac allegro okna graficznego');
    al_exit;
    EXIT;
  end;
end;

procedure sciany;
begin
  al_rectfill(al_screen, 0, 0, 10, 600, al_makecol(24,0,24));
  al_rectfill(al_screen, 0, 0, 800, 10, al_makecol(24,0,24));
  al_rectfill(al_screen, 790, 0, 800, 600, al_makecol(24,0,24));
  al_rectfill(al_screen, 10, 590, 800, 600, al_makecol(24,0,24));
end;

procedure rysuj;
begin
  al_clear_to_color(al_screen, al_makecol(64,0,64));
  sciany;
end;


var koniec_gry:integer;

  klawisz, klawisz2:integer;
  pozx1,pozy1:integer;
  zycia:integer;

BEGIN
  inicjalizacja;

  koniec_gry:=99999;
  pozx1:=400;
  pozy1:=300;
  zycia:=5;
  klawisz2:=0;
  while (koniec_gry>0) do
  begin
    rysuj;

    if al_keypressed then
    begin
      klawisz:=al_readkey;
      if ((klawisz2<>21248) and (klawisz=20992)) then
      begin
        pozx1:=pozx1-1;
        klawisz2:=klawisz;
      end;
      if ((klawisz2<>20992) and (klawisz=21248)) then
      begin
        pozx1:=pozx1+1;
        klawisz2:=klawisz;
      end;
      if ((klawisz2<>21760) and (klawisz=21504)) then
      begin
        pozy1:=pozy1-1;
        klawisz2:=klawisz;
      end;
      if ((klawisz2<>21504) and (klawisz=21760)) then
      begin
        pozy1:=pozy1+1;
        klawisz2:=klawisz;
      end;
      if klawisz=15131 then koniec_gry:=1;
    end;
    if klawisz2=20992 then pozx1:=pozx1-1;
    if klawisz2=21248 then pozx1:=pozx1+1;
    if klawisz2=21504 then pozy1:=pozy1-1;
    if klawisz2=21760 then pozy1:=pozy1+1;
    al_circlefill(al_screen, pozx1, pozy1,10, al_makecol(0,255,0));

    if ((pozx1<20) or (pozx1>780) or (pozy1<20) or (pozy1>580)) then
    begin
      zycia:=zycia-1;
      pozx1:=400;
      pozy1:=300;
      writeln('zycia: ',zycia);
    end;
    if(zycia=0) then
    begin
      koniec_gry:=1;
    end;

    al_rest(10);
    koniec_gry:=koniec_gry-1;

  end;
  al_keypressed;
  al_exit;
END.
