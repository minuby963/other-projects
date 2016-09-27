import java.awt.Dimension;
import javax.swing.BorderFactory;
import javax.swing.JPanel;

public class LPanel extends JPanel {
	private static final long serialVersionUID = 1L;
	private final int L_WIDTH = 200;
	private final int L_HEIGHT = 200;
	
	LPanel(){

		setPreferredSize(new Dimension(L_WIDTH,L_HEIGHT));	
		
		setBorder(
				BorderFactory.createCompoundBorder(
						BorderFactory.createTitledBorder("Lewy panel"),
						BorderFactory.createEmptyBorder(0,0,0,0)
				)
		);	
			
	}

}
