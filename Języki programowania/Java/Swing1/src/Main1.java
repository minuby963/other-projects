import java.awt.FlowLayout;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;
import javax.swing.UIManager;

public class Main1 extends JPanel {
	private static final long serialVersionUID = 1L;
	
	private Main1(){
		
		createAndShowGUI();
		 
	}
	
	private static void createAndShowGUI() {
		JFrame ramka = new JFrame("GRA!");
		ramka.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		ramka.setSize(840, 540);	
		
		ramka.setLayout(new FlowLayout());
		
		
		ramka.add(new RPanel());
		ramka.add(new LPanel());
		//ramka.setContentPane(new LPanel());
		ramka.setResizable(false);
		ramka.setVisible(true);
	}	

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable(){
			public void run(){
				UIManager.put("swing.boltMetal", Boolean.FALSE);
				createAndShowGUI();
			}
		});
		
	}

}
