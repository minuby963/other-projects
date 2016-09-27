import java.awt.Point;
import java.util.Random;

public class Logika {
	int[][] tab1= new int[10][10];
	
	Logika(){
		for(int i=0;i<tab1.length;i++)
			for(int j=0;j<tab1[i].length;j++)
				tab1[i][j]=0;
	}
	
	static Logika Aktualizujlogike(){
		
		
		return null;
	}
	public void UpdateGame(long gameTime, Point mousePosition)
    {
		Random generator = new Random(); 
		int rand = generator.nextInt(5) + 1;
		
		
		for(int i=0;i<tab1.length;i++)
			for(int j=0;j<tab1[i].length;j++){
				tab1[i][j]=rand;
				System.out.print(tab1[i][j]+", ");
			}
				
		
    }
	
}
