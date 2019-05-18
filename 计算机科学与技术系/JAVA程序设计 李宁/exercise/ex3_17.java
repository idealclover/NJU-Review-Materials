import java.io.*;

public class ex3_17
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.
            in));
        int value;
        while (true)
        {
            try
            {
                System.out.print("Input a number Plz:");
                value = Integer.parseInt(reader.readLine());
                if (value <= 1)
                {
                    System.out.println(
                        "This number does not measure up,again Plz!");
                }
                else
                {
                    System.out.print("The number's prime gene:");
                    for (int i = 2; i <= value; i++)
                    {
                        if (value % i == 0 && isPrime(i))
                        {
                            System.out.print(i + " ");
                        }
                    }
                    break;
                }
            }
            catch (NumberFormatException e)
            {
                System.out.println("Number Format Error!Again Plz!");
            }
        }
    }

    private static boolean isPrime(int value)
    {
        for (int i = 2; i <= value / 2; i++)
        {
            if (value % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}
