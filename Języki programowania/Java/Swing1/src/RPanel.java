import java.awt.Dimension;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JPanel;

public class RPanel extends JPanel {
	private static final long serialVersionUID = 1L;

	RPanel(){
		JButton pauza = new JButton("Pauza");
		
		setPreferredSize(new Dimension(120, 500));	
		this.setBorder(
				BorderFactory.createCompoundBorder(
						BorderFactory.createTitledBorder("Prawy panel"),
						BorderFactory.createEmptyBorder(0,0,0,0)
				)
		);
		

		
		//prawyPanel.setSize(300, 300);
		//prawyPanel.setLocation(10, 100);
		//int a = FlowLayout.RIGHT;
		//prawyPanel.setLayout(new FlowLayout(a));
		//pauza.setLayout(new FlowLayout(a));
		
		
		this.add(pauza);
	}
}
