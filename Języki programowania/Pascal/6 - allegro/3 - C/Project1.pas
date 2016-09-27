program Project1;

uses allegro;

const
  ScreenWidth= 1200;
  ScreenHeight= 720;

procedure inicjalizacja;
begin
  al_init;
  al_install_keyboard;
  al_set_gfx_mode(Al_GFX_AUTODETECT_WINDOWED,ScreenWidth,ScreenHeight,0,0);
end;

begin


end.

