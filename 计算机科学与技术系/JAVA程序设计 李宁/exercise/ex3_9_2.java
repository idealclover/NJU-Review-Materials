import java.io.*;

public class ex3_9_2
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
                float f = Float.parseFloat(s);
                int i = (int) f;
                System.out.println("Integer part:" + i);
                float d = f - i;
                if (d == 0)
                {
                    System.out.println("No decimal part!");
                }
                else
                {
                    System.out.println("Decimal part :" + d);
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
