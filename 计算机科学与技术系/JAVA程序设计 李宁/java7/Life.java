import java.applet.*;
import java.awt.*;
/**
 * This type was created in VisualAge.
 */
public class Life extends Applet {
	StringBuffer buffer=new StringBuffer();
/**
 * Cleans up whatever resources are being held. If the applet is active
 * it is stopped.
 * 
 * @see #init
 * @see #start
 * @see #stop
 */
public void destroy() {
	super.destroy();

	showMessage("[destory]Wha,help me!!!");
}
/**
 * Initializes the applet.
 * 
 * @see #start
 * @see #stop
 * @see #destroy
 */
public void init() {
	super.init();

	resize(1000,200);
	showMessage("[init]Now the Applet come into being...");
}
/**
 * Draws the text on the drawing area.
 * @param g the specified Graphics window
 */
public void paint(Graphics g) {
	g.drawRect(0,0,1000-1,200-1);
	g.drawString(buffer.toString(),5,15);	
}
/**
 * This method was created in VisualAge.
 * @param newMessage java.lang.String
 */
public void showMessage(String newMessage) {
	buffer.append(newMessage);
	repaint();
}
/**
 * Called to start the applet. You never need to call this method
 * directly, it is called when the applet's document is visited.
 * @see #init
 * @see #stop
 * @see #destroy
 */
public void start() {
	super.start();

	showMessage("[start]Now the Applet begin to work...");
}
/**
 * Called to stop the applet. It is called when the applet's document is
 * no longer on the screen. It is guaranteed to be called before destroy()
 * is called. You never need to call this method directly.
 * @see #init
 * @see #start
 * @see #destroy
 */
public void stop() {
	super.stop();

	showMessage("[stop]Now the Applet begin reset...");
}
}
