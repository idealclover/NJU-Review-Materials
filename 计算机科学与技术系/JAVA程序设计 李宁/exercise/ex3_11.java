import java.io.*;

public class ex3_11
{
    public static void main(String[] args) throws IOException
    {
        System.out.println("Please input a string end with '#'");
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.
            in));
        char ch = '#';
        char value;
        while (true)
        {
            value = (char) reader.read();
            if (value == '#')
            {
                break;
            }
            else if (value < 'a' || value > 'z')
            {
                continue;
            }

            if (ch == '#')
            {
                ch = value;
            }
            else if (value < ch)
            {
                ch = value;
            }
        }

        if (ch == '#')
        {
            System.out.println("You inputed blank string!");
        }
        else
        {
            System.out.println("The minimum char: " + ch);
        }
    }
}
