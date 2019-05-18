import java.io.*;

public class ex3_10
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.
            in));
        System.out.println("Plz input 10 integers:");
        int max = 0, min = 0;
        for (int i = 0; i < 10; i++)
        {
            System.out.print("Integer " + i + " : ");
            try
            {
                int value = Integer.parseInt(reader.readLine());
                if (i == 0 || value < min)
                {
                    min = value;
                }
                if (i == 0 || value > max)
                {
                    max = value;
                }
            }
            catch (NumberFormatException e)
            {
                System.out.println("Number Format Error,Input Again Plz!");
                i--;
            }
        }
        System.out.println("max :" + max);
        System.out.println("min :" + min);
    }
}
