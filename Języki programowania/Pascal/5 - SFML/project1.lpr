program project1;


uses
  SfmlGraphics in 'C:\lazarus\PasSFML-master\Source\SfmlGraphics',
  SfmlWindow in 'C:\lazarus\PasSFML-master\Source\SfmlWindow',
  SfmlSystem in 'C:\lazarus\PasSFML-master\Source\SfmlSystem';

var
  Window: TSfmlRenderWindow;
  Mode: TSfmlVideoMode;
begin
  Mode.Width := 800;
  Mode.Height := 600;
  Mode.BitsPerPixel := 32;
   Window := TSfmlRenderWindow.Create(Mode, AnsiString('SFML Window'),
    [sfResize, sfClose], nil);

  Window := TSfmlRenderWindow.Create(SfmlVideoMode(640, 480),
    'SFML Application', [sfClose]);

  readln;
end.

