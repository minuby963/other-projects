program Project1;

uses
 allegro, sysutils;

begin
  al_set_gfx_mode (AL_GFX_SAFE, 640, 480, 0, 0);

  while al_keypressed do
  begin
    al_exit;
  end;
  readln;
end.
