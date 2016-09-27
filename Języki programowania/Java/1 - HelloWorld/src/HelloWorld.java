import static java.lang.Math.*;
import java.util.Scanner;

public class HelloWorld {

	public static void main(String[] args) {
		String str=" abc";
		String a=str.substring(0,2)+str.substring(3,4);
		double liczba=0.7;
		double liczba2 = pow(liczba, 2)+0.1;
		System.out.println(true+a+" = "+(int)liczba2);
		
		String str1;
		Scanner odczyt1= new Scanner(System.in);
		str1= odczyt1.next();
		int i1 = odczyt1.nextInt();
		odczyt1.close();
		System.out.println("str1 = "+str1+"; i1 = "+i1);
		

		
		

	}

}
