import java.io.*;

public class ex3_14
{
    public static void main(String[] args) throws IOException
    {
        int value;
        while (true)
        {
            System.out.print("Input a number between 1 and 12 Plz:");
            BufferedReader reader = new BufferedReader(new InputStreamReader(
                System.
                in));
            try
            {
                value = Integer.parseInt(reader.readLine());
                if (value >= 1 && value <= 12)
                {
                    break;
                }
                else
                {
                    System.out.println(
                        "This number does not measure up,again Plz!");
                }
            }
            catch (NumberFormatException e)
            {
                System.out.println("Number Format Error,again Plz!");
            }
        }

        switch (value)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                System.out.println("This month has 31 days");
                break;
            case 2:
                System.out.println("This month has 28 or 29 days");
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                System.out.println("This month has 30 days");
                break;
        }
    }
}
