import java.io.*;

public class Student
{
    private int ID;
    private int classID;
    private String name;
    private String sex;
    private int age;

    public static String MALE = "male";
    public static String FEMALE = "female";

    public int getID()
    {
        return ID;
    }

    public int getClassID()
    {
        return classID;
    }

    public String getSex()
    {
        return sex;
    }

    public int getAge()
    {
        return age;
    }

    public void setAge(int age)
    {
        this.age = age;
    }

    public Student(int ID, int classID, String name, String sex, int age)
    {
        this.ID = ID;
        this.classID = classID;
        this.name = name;
        setAge(age);
        this.sex = sex;
    }

    public String toString()
    {
        StringBuffer buffer = new StringBuffer();
        buffer.append("学号：");
        buffer.append(ID);
        buffer.append("；班级：");
        buffer.append(classID);
        buffer.append("；姓名：");
        buffer.append(name);
        buffer.append("；性别：");
        if (sex.equals(MALE))
        {
            buffer.append("男");
        }
        else if (sex.equals(FEMALE))
        {
            buffer.append("女");
        }
        else
        {
            buffer.append(sex);
        }
        buffer.append("；年龄：");
        buffer.append(age);
        buffer.append("；");
        return buffer.toString();
    }

    public static void main(String[] args) throws IOException,
        NumberFormatException
    {
        System.out.println("作业2-1：Student类");
        System.out.println("by slhynju");
        System.out.println();
        System.out.println("Stuent类由学号、班级号、姓名、性别、年龄构成。");
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("请输入学号：");
        String s = r.readLine();
        int ID = Integer.parseInt(s);
        System.out.print("请输入班级号：");
        s = r.readLine();
        int classID = Integer.parseInt(s);
        System.out.print("请输入姓名：");
        String name = r.readLine();
        System.out.print("请输入性别，M表示男，F表示女，其他输入将保留不变：");
        String sex = r.readLine();
        if (sex.equalsIgnoreCase("M"))
        {
            sex = MALE;
        }
        else if (sex.equalsIgnoreCase("F"))
        {
            sex = FEMALE;
        }
        System.out.print("请输入年龄：");
        s = r.readLine();
        int age = Integer.parseInt(s);
        Student student = new Student(ID, classID, name, sex, age);
        System.out.println();
        System.out.println("您输入的数据为：");
        System.out.println(student.toString());
    }
}
