import java.awt.Component;
import java.awt.Container;
import java.awt.FlowLayout;
import javax.swing.JButton;
import javax.swing.JFrame;

public class Frame1 extends JFrame{

	public Frame1(){
		super("GRA!");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(640, 600);
		setResizable(false);
		setLocation(50,50);
		
		
		Container kontener = getContentPane();
		kontener.add(new JButton ("Przycisk 1"));
		kontener.add(new JButton ("Przycisk 2"));
		kontener.add(new JButton ("Przycisk 3"));
		
		FlowLayout ustawienie = new FlowLayout(FlowLayout.CENTER);
		kontener.setLayout(ustawienie);
		

		
		
		setVisible(true);
	}
}
