package exercise;

/**
 * <p>Title: </p>
 * <p>Description: </p>
 * <p>Copyright: Copyright (c) 2003</p>
 * <p>Company: </p>
 * @author not attributable
 * @version 1.0
 */

import java.applet.*;
import java.awt.*;
import java.awt.event.*;

public class ch3_16
    extends Applet
    implements ActionListener
{
    Label label1;
    TextField input1, input2;
    Button btn1;
    int high = 0, low = 0;

    public void init()
    {
        label1 = new Label("请输入上限、下限整数");
        input1 = new TextField(4);
        input2 = new TextField(4);
        btn1 = new Button("运算");
        add(label1);
        add(input1);
        add(input2);
        add(btn1);
        btn1.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e)
    {
        high = Integer.parseInt(input1.getText());
        low = Integer.parseInt(input2.getText());
        repaint();
    }

    public void paint(Graphics g)
    {
        if (input1.getText().length() == 0 && input2.getText().length() == 0)
        {
            return;
        }

        if (low <= 0 || high <= 0 || low > high)
        {
            g.drawString("输入不符合要求!", 2, 40);
            return;
        }

        g.drawString("上、下限之间的素数有：", 2, 40);
        int k = 0;
        LL:
        for (int i = low; i <= high; i++)
        {
            for (int j = 2; j < i / 2; j++)
            {
                if (i % j == 0)
                {
                    continue LL;
                }
            }
            g.drawString("" + i, k % 10 * 40, 70 + k / 10 * 20);
            k++;
        }
    }
}
