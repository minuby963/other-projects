import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.Point;
import java.util.Random;

public class GameLogic {
	public Area1 area1;
	private int numberOfColors; //MAX 10;
	private Random generator;
	private int rand;
	int readyToResearch;

	
	public GameLogic()
    {
        //Framework.gameState = Framework.GameState.GAME_CONTENT_LOADING;
        
        Thread threadForInitGame = new Thread() {
            @Override
            public void run(){
                // Sets variables and objects for the game.
                Initialize();
                // Load game files (images, sounds, ...)
                //LoadContent();
                
                //Framework.gameState = Framework.GameState.PLAYING;
            }
        };
        threadForInitGame.start();
    }
	
	private void Initialize()
    {     
		area1 = new Area1();
		numberOfColors=3;                        //******numberOfColors*******//
		generator = new Random();
		readyToResearch = 0;
		
		
		
		for(int i=0;i<area1.tab.length;i++){
			for(int j=0;j<area1.tab[i].length;j++){
				rand = generator.nextInt(numberOfColors);
				area1.tab[i][j]=rand;
				
				System.out.print(area1.tab[i][j]+" ");//**********wypisywanie**********//
			}
			System.out.println();                     //**********-    ||    -*********//
			
		}
		
    }
	
	void UpdateGame(long gameTime, Point mousePosition){
		
		int counter=1;
		int memorizer=-1;
		boolean getOut = false;
		if(readyToResearch==2){
			readyToResearch=0;
			for(int i=0;i<area1.tab.length;i++){
				if(getOut==true)break;
				for(int j=0;j<area1.tab[i].length;j++){
					
					if(memorizer!=area1.tab[i][j]){
						memorizer=area1.tab[i][j];
						counter=1;
					}
					else{
						counter++;
						System.out.println();     
						System.out.println("counter = "+counter+" memorizer = "+memorizer+" i: "+i+" j: "+j);    
					}
					if(counter==3){
						readyToResearch=1;
						
						if(j+1<area1.tab[i].length){
							if(area1.tab[i][j+1] == memorizer){
								
								counter++;
								j++;
								System.out.println();     
								System.out.println("counter = "+counter+" memorizer = "+memorizer+" i: "+i+" j: "+j);    
								
								if((j+1<area1.tab[i].length) && (area1.tab[i][j+1] == memorizer)){
									counter++;
									j++;
									System.out.println();     
									System.out.println("counter = "+counter+" memorizer = "+memorizer+" i: "+i+" j: "+j);      
								}
								
							}	
						}
						
						for(int k = i;k>0;k--){
							for(int p = counter-1;p>=0;p--){
								area1.tab[k][j-p] = area1.tab[k-1][j-p];
							}
						}
						for(int p = counter-1;p>=0;p--){
							rand = generator.nextInt(numberOfColors);
							area1.tab[i][j-p] = rand;
						}
						counter=1;
						getOut=true;
						memorizer=-1;
						break;
					}
				}
				counter=1;
				memorizer=-1;
			}
		}
		
		//*********************************wypisywanie*********************************//
		System.out.println(); System.out.println(); System.out.println(); 
		for(int i=0;i<area1.tab.length;i++){
			for(int j=0;j<area1.tab[i].length;j++){
				System.out.print(area1.tab[i][j]+" ");}System.out.println();}
		//*********************************wypisywanie*********************************//
		
		
	}
	
	
	public void Draw(Graphics2D g2d, Point mousePosition)
    {
        //g2d.setFont(font);
		if(g2d == null)
			System.out.println("g2s == null");  //**********czy null**********//
		
        g2d.setColor(Color.darkGray);
        g2d.drawLine(mousePosition.x, mousePosition.y, 0, 0);
        g2d.drawLine(mousePosition.x, mousePosition.y, 0, 0);
        for(int i = 1; i<7;i++){
        	g2d.drawLine(100*i, 0, 100*i, 600);
        	g2d.drawLine(0, 100*i, 600, 100*i);
        }
        for(int i=0;i<area1.tab.length;i++){
			for(int j=0;j<area1.tab[i].length;j++){
				switch( area1.tab[i][j] ){
					case 0:
						g2d.setColor(Color.black);
						break;
					case 1:
						g2d.setColor(Color.red);
						break;
					case 2:
						g2d.setColor(Color.blue);
						break;
					case 3:
						g2d.setColor(Color.green);
						break;
					case 4:
						g2d.setColor(Color.yellow);
						break;
					case 5:
						g2d.setColor(Color.orange);
						break;	
					case 6:
						g2d.setColor(Color.cyan);
						break;	
					case 7:
						g2d.setColor(Color.pink);
						break;	
					case 8:
						g2d.setColor(Color.gray);
						break;	
					case 9:
						g2d.setColor(Color.magenta);
						break;	
					case 10:
						g2d.setColor(Color.orange);
						break;	
					default:
						System.out.println("Probably numberOfColors is bigger than 10!");
						break;						
				}
				g2d.fillRect(40+100*j,40+100*i, 20, 20);
		        
			}
		}

    }
}
