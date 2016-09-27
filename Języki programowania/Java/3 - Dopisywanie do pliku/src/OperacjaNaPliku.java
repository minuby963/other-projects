import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class OperacjaNaPliku {
	
	String plik1;
	boolean dopisywanie;
	OperacjaNaPliku(String _plik1, boolean _dopisywanie){
		plik1=_plik1;
		dopisywanie=_dopisywanie;
	}
	
	void UtworzPlik(){
		
		File stPlik1 = new File(plik1);
		try{
			if(!stPlik1.exists()){
				stPlik1.createNewFile();
			}		
		}
		catch(IOException e){
			System.out.println("B³¹d podczas tworzenia pliku. ");
		}
		
	}
	
	public void DopiszDoPliku(String tekst) throws IOException{
		FileWriter dodajDoPliku = new FileWriter(plik1, dopisywanie);
		PrintWriter dopisz1 = new PrintWriter(dodajDoPliku);
		dopisz1.println(tekst);
		dopisz1.close();
	}

}
