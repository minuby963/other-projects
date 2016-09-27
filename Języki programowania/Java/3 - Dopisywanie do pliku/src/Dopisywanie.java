import java.io.IOException;
import java.util.Scanner;

public class Dopisywanie {
	
	public static void main(String[] args) {
		String plik1 = "dane1.txt";
		boolean czyDopisac = true;
		String tekst = "aaa";
		OperacjaNaPliku opPlik1 = new OperacjaNaPliku(plik1,czyDopisac);
		
		Scanner odczyt1 = new Scanner(System.in);
		
		System.out.println("Podaj tekst do dopisania: ");
		tekst = odczyt1.nextLine();
		
		opPlik1.UtworzPlik();
		try{
			opPlik1.DopiszDoPliku(tekst);
		}
		catch(IOException e){
			System.out.println("IOEception. ");
		}
		odczyt1.close();
	}

}
