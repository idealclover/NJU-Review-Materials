import java.io.*;

public class ex3_9
{
    public static void main(String args[]) throws IOException
    {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.
            in));
        while (true)
        {
            System.out.print("Input a float number:");
            try
            {
                String s = reader.readLine();
                int i = (int) Float.parseFloat(s);
                System.out.println("Integer part:" + i);
                int d = s.indexOf('.');
                if (d != -1)
                {
                    System.out.print("Decimal part:");
                    if (s.charAt(0) == '-')
                    {
                        System.out.print('-');
                    }
                    System.out.println("0." + s.substring(d + 1));
                }
                else
                {
                    System.out.println("No decimal part!");
                }
                break;
            }
            catch (NumberFormatException e)
            {
                System.out.println("Number Format Error!Input Again Plz!");
            }
        }
    }
}
