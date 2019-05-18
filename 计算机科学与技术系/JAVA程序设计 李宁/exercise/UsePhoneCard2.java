import java.applet.*;
import java.awt.*;
import java.awt.event.*;

public class UsePhoneCard2
    extends Applet
    implements ActionListener
{
    Label card, pass, bal, connectNum;
    TextField input1, input2, input3, input4;
    Button btn;
    long cardNumber;
    private int password;
    double balance;
    String connectNumber;

    public void init()
    {
        card = new Label("卡号：");
        input1 = new TextField(5);
        pass = new Label("密码：");
        input2 = new TextField(5);
        bal = new Label("金额：");
        input3 = new TextField(5);
        connectNum = new Label("接入号：");
        input4 = new TextField(5);
        btn = new Button("创建");
        add(card);

        add(input1);
        add(pass);
        add(input2);
        add(bal);
        add(input3);
        add(connectNum);
        add(input4);
        add(btn);
        btn.addActionListener(this);
    }

    public void paint(Graphics g)
    {
        g.drawString("卡号" + cardNumber, 10, 50);
        g.drawString("密码" + password, 10, 70);
        g.drawString("金额" + balance, 10, 90);
        g.drawString("接入号" + connectNumber, 10, 110);
    }

    public void actionPerformed(ActionEvent e)
    {
        cardNumber = Long.parseLong(input1.getText());
        password = Integer.parseInt(input2.getText());
        balance = Double.parseDouble(input3.getText());
        connectNumber = input4.getText();
        repaint();
    }
}
