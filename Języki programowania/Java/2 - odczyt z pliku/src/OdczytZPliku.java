import java.util.Scanner;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.RandomAccessFile;

public class OdczytZPliku {

	public static void main(String[] args) throws IOException {
		
		/*File plik1 = new File("dane.txt");
		Scanner odczyt1 = new Scanner(plik1);
		//Scanner odczyt1 = new Scanner (new File("dane.txt"));
		String s1 = odczyt1.next();
		String l1 = odczyt1.nextLine();
		int i1 = odczyt1.nextInt();
		System.out.println("s1 = "+s1+"; l1 = "+l1+"; i1 = "+i1+";");
		int[] tab1 = new int[20];
		PrintWriter zapisz1 = new PrintWriter("dane.txt");
		for(int i=0;i<20;i++)
		{
			tab1[i]=i+i;
			zapisz1.println(i+" "+s1+" s1s1s1s1s1"+" "+tab1[i]);
		}
		zapisz1.close();
		
		while(odczyt1.hasNextLine())
		{
			System.out.println(odczyt1.nextLine());
		}
		odczyt1.close();*/
		
		
		////////////////////////////BINARY//////////////////////////////
		
		String plik2="binary.txt";
		String plik3="binary2.txt";
		byte [] b1 = new byte[] {1,2,3,4,5,6,7,8};
		FileInputStream sWej2 = new FileInputStream(plik2);
		
		
		sWej2.read(b1);
		
		for(int i=0;i<b1.length;i++){
			System.out.println("b1["+i+"]: "+b1[i]);
		}
		System.out.println();
		
		File nowy = new File(plik3);
		if(!nowy.exists()){
			nowy.createNewFile();
		}
		
		FileOutputStream sWyj2 = new FileOutputStream(plik3);
		sWyj2.write(b1);
		
		
		
		System.out.println(plik3);
		sWyj2.close();
		sWej2.close();
		RandomAccessFile sWW1 = null;
		try{
			
			sWW1 = new RandomAccessFile(plik3, "rw");
			
		}
		catch(FileNotFoundException e){
			System.out.println("FileNotFoundException");
		}
		try{
			sWW1.write(b1);
		}
		catch(IOException e){
			System.out.println("IOException1");
		}
		try{
			if(sWW1!=null){
				sWW1.close();
			}
		}
		catch(IOException e){
			System.out.println("IOException2");
		}
		

		/*DataInputStream sWej1 = new DataInputStream(new FileInputStream(plik2));
		FileOutputStream sWyj1 = new FileOutputStream(plik2);
		
		int b = 0;
		sWyj1.write(b);
		//System.out.println(b);
		
		
		
		
		sWej1.close();
		sWyj1.close();*/
		
		
	}

}
