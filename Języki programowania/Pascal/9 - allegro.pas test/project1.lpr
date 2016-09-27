program project1;

uses allegro;

const
  ScreenWidth= 1200;
  ScreenHeight= 720;

procedure inicjalizacja;
begin
al_init;
al_install_keyboard;
al_install_timer;
al_install_sound(AL_DIGI_AUTODETECT, AL_MIDI_AUTODETECT);
al_set_color_depth(32);
al_set_gfx_mode(Al_GFX_AUTODETECT_WINDOWED,ScreenWidth,ScreenHeight,0,0);
al_set_window_title('test');

end;


begin
  inicjalizacja;

  al_textout_centre_ex(al_screen,al_font,'TROLOLOLOLO', ScreenWidth div 2, ScreenHeight div 3, al_makecol(164,46,64), -1);
  al_readkey();
  al_exit;
end.

