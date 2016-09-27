import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;

public class GameMain extends JFrame {
	private static final long serialVersionUID = 1L;
	
	public final int SCREEN_WIDTH = 740;
	public final int SCREEN_HEIGHT = 640;
	
	GameMain(){
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(SCREEN_WIDTH, SCREEN_HEIGHT);	
		setTitle("Game!");
		//setLayout(new FlowLayout());
		
		//this.setUndecorated(true);


		JPanel mainPanel = new JPanel();
		   
		RPanel rPanel = new RPanel();

		this.add(mainPanel);
		mainPanel.add(new GUI1());
		mainPanel.add(rPanel);

		setResizable(false);
		//pack();
		setVisible(true);
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new GameMain();
            }
        });
	}

}
