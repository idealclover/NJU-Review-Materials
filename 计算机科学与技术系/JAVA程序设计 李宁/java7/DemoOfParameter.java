import java.applet.*;
import java.awt.*;
/**
 * 在此处插入类型说明。
 * 创建日期：(2000-12-14 9:26:51)
 * @author：
 */
public class DemoOfParameter extends Applet {
public void paint(Graphics g){
	String fontName=getParameter("font");
//	fontName = "Algerian";
//	System.out.println(fontName);
	String sizeName=getParameter("size");
//	sizeName = "24";
//	System.out.println(sizeName);
	int fontSize=Integer.parseInt(sizeName);
	Font fnt=new Font(fontName,Font.BOLD,fontSize);
	g.setFont(fnt);
	g.drawString("The Font and Size're correct?",40,50);
}
}
