import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JPanel;

public class GUI1 extends JPanel implements MouseListener, KeyListener {
	private static final long serialVersionUID = 1L;
	
	//public final int SCREEN_WIDTH = 600;
	//public final int SCREEN_HEIGHT = 600;
	
	private static boolean[] mouseState = new boolean[3];
	
	public boolean playing;
	
	public static final long secInNanosec = 1000000000L;
    public static final long milisecInNanosec = 1000000L;
    
    private final int GAME_FPS = 60;
    private final long GAME_UPDATE_PERIOD = secInNanosec / GAME_FPS;
    private long gameTime;
    private long lastTime;
    
    private GameLogic gameLogic;
	
	public GUI1(){
		super();
		this.addKeyListener(this);
        this.addMouseListener(this);
        
        this.setFocusable(true);
        this.setBackground(Color.white);
        
        this.setPreferredSize(new Dimension(600,600));
        
        //this.setDoubleBuffered(true);
        //this.setSize(SCREEN_WIDTH, SCREEN_HEIGHT);
        
        playing = true;
        gameLogic = new GameLogic();
        
        Thread gameThread = new Thread() {
            @Override
            public void run(){
                GameLoop();
            }
        };
        gameThread.start();
	}
	
	private void GameLoop(){
        //long visualizingTime = 0, lastVisualizingTime = System.nanoTime();
        long beginTime, timeTaken, timeLeft;
		
		while(playing){
			beginTime = System.nanoTime();
			gameTime += System.nanoTime() - lastTime;
			//System.out.println("mouse: "+mousePosition().x+"  "+mousePosition().y);
            gameLogic.UpdateGame(gameTime,mousePosition());
            lastTime = System.nanoTime();
            
            
			repaint();
			
            timeTaken = System.nanoTime() - beginTime;
            timeLeft = (GAME_UPDATE_PERIOD - timeTaken) / milisecInNanosec;
            if (timeLeft < 10) 
                timeLeft = 10;
            try {
                 Thread.sleep(timeLeft);
            } catch (InterruptedException ex) { }
		}
	}
	
	@Override
	public void paintComponent(Graphics g)
	{
		Graphics2D g2d = (Graphics2D)g;        
		super.paintComponent(g2d);        
	    Draw(g2d);
	}
	
    public void Draw(Graphics2D g2d)
    {
    	if(gameLogic == null)
    		System.out.println("gameLogic == null! ");
    	
		gameLogic.Draw(g2d, mousePosition());   
    }
	
	private Point mousePosition()
    {
        try
        {
            Point mp = this.getMousePosition();
            
            if(mp != null)
                return this.getMousePosition();
            else
                return new Point(0, 0);
        }
        catch (Exception e)
        {
            return new Point(0, 0);
        }
    }
	
	private void mouseKeyStatus(MouseEvent e, boolean status)
    {
        if(e.getButton() == MouseEvent.BUTTON1)
            mouseState[0] = status;
        else if(e.getButton() == MouseEvent.BUTTON2)
            mouseState[1] = status;
        else if(e.getButton() == MouseEvent.BUTTON3)
            mouseState[2] = status;
    }
	

	@Override
	public void keyPressed(KeyEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void keyReleased(KeyEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void keyTyped(KeyEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseClicked(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseEntered(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseExited(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mousePressed(MouseEvent e) {
		mouseKeyStatus(e, true);	
	}

	@Override
	public void mouseReleased(MouseEvent e) {
		mouseKeyStatus(e, false);
		
	}

}
