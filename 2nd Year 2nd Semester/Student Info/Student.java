import java.io.PrintWriter;
import java.util.Scanner;
import java.io.File;
import java.io.*;

//* @author (Hasib Iqbal)
//* @version (10/10/2016)

public class Student {
    Scanner input = new Scanner(System.in);

    int id;
    String name;
    String Department ;
    String University ;
    double[] GPA = new double[8];
    double[][] CnG = new double[10][2];//Credit & Grade
    String sub1,sub2,sub3,sub4,sub5,sub6;
    double CGPA;

    public Student(int Id,String Name,String department,String university)
    {
        id = Id;
        name = Name;
        Department = department;
        University = university ;
    }


    // Method to set Credit and Corresponding Grades
    public void setCreditnGrade()
    {
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<1;j++)
            {
                System.out.print("Enter Credit of Sub "+(i+1)+" : ");
                CnG[i][j]=input.nextDouble();
                System.out.print("Enter Grade of Sub "+(i+1)+" : ");
                CnG[i][j+1]=input.nextDouble();
            }
        }
    }

    //Method to set GPA of Various terms
    public void setGPAv()
    {
        for(int i=0;i<8;i++)
        {
            System.out.print("Enter GPA of Sem " + (i+1) +" : ");
            GPA[i]=input.nextDouble();
        }
    }

    // Define a method to compute the GPA from the given Credits and Grades of all the subjects
    public double computeGPAById()
    {
        //write yor code here
        double gpa =0;
        double total = 0;
        for(int i=0;i<10;i++)
            for(int j=0;j<1;j++)
            {
                gpa+=CnG[i][j]*CnG[i][j+1];
                total += CnG[i][j];
            }
        gpa = gpa / total;
        System.out.println("Current Term GPA is "+gpa);
        return gpa;
    }

    //Method to compute CGPA
    public double computeCGPAByID()
    {
        // Write your code here
        double cgpa = 0;
        int count = 0;
        for(int i=0;i<8;i++)
        {
            if(GPA[i] == 0) continue;
            count++;
            cgpa+=GPA[i];
        }
        cgpa/=count;
        CGPA = cgpa;
        return cgpa;
    }


    //Define a method to print the students details.
    public void studentDetailsById()
    {
        //write your code here
        System.out.println("Name          : "+name);
        System.out.println("ID            : " + id);
        System.out.println("Department    : " + Department);
        System.out.println("University    : " + University);
        System.out.println("Current CGPA  : " + CGPA);
    }


    //method to update information of students
    public void updateStudentById()
    {
        //Write your code here
        System.out.print("Enter Name : ");
        name = input.nextLine();
        System.out.print("Enter Department : ");
        Department = input.nextLine();
        System.out.print("Enter University : ");
        University = input.nextLine();
    }


    public void saveStudent()
    {
        try{
            File outputFile = new File("info.txt");
            PrintWriter writer = new PrintWriter(outputFile);

            writer.println("Name  : "+name);
            writer.println("ID  : " + id);
            writer.println("Department  : " + Department);
            writer.println("University  : " + University);
            writer.println("Current CGPA  : " + CGPA);

            writer.close();
        }
        catch(Exception e)
        {
            System.out.println(e);
        }

    }


    public static void main(String[] args)
    {
        Student[] students = new Student[50];
        Scanner input = new Scanner(System.in);

        students[0] = new Student(1407001,"Bikash","CSE","KUET");
        students[1] = new Student(1407002,"Tushar","CSE","KUET");
        students[2] = new Student(1407003,"Hasib","CSE","KUET");
        students[3] = new Student(1407004,"Tawhid","CSE","KUET");
        students[4] = new Student(1407005,"Mehedi","CSE","KUET");
        students[5] = new Student(1407006,"Zarin","CSE","KUET");
        students[6] = new Student(1407007,"Shahdat","CSE","KUET");
        students[7] = new Student(1407008,"Shopto","CSE","KUET");
        students[8] = new Student(1407009,"Shanto","CSE","KUET");
        students[9] = new Student(1407010,"Ornob","CSE","KUET");


        int j=10;
        int st=0;
        System.out.print("Enter 1 to ADD New Student or 0 otherwise : ");
        st = input.nextInt();
        if(st==1)
        {
            int iD;
            String nAme;
            String dEpartment ;
            String uNiversity ;

            input.nextLine();
            System.out.println("Enter Name : ");
            nAme = input.nextLine();

            input.nextLine();
            System.out.println("Enter Id : ");
            iD = input.nextInt();

            input.nextLine();
            System.out.println("Enter Department : ");
            dEpartment = input.nextLine();

            input.nextLine();
            System.out.println("Enter University : ");
            uNiversity = input.nextLine();

            students[j++] = new Student(iD,nAme,dEpartment,uNiversity);

        }

        boolean ex=true;
        while(ex)
        {
        int roll,ind=1;
        System.out.print("Enter Student ID : ");
        roll = input.nextInt();

        for(int i=0;i<10;i++)
        {
            if(students[i].id==roll)
            {
                ind = i;
                break;
            }
        }

        boolean choice2 = true;
        while(choice2)
        {
        int choice;
        System.out.println("Hello "+students[ind].name);
        System.out.println("Enter 1 to Set Credit & Grade of Current Term\nEnter 2 to Set GPA of All Terms\nEnter 3 to Calculate Current CGPA \nEnter 4 to Update Students Basic Information\nEnter 5 to See Details\nEnter 6 to See GPA of Current Term/nEnter 0 to EXIT This Profile");
        choice = input.nextInt();

        if(choice == 1)
        {
            students[ind].setCreditnGrade();
        }
        else if(choice == 2)
        {
            students[ind].setGPAv();
        }

        else if(choice == 3)
        {
            students[ind].computeCGPAByID();
        }

        else if(choice == 4)
        {
            students[ind].updateStudentById();
        }

        else if(choice == 5)
        {
            students[ind].studentDetailsById();
        }

        else if(choice == 6)
        {
            students[ind].computeGPAById();
        }

        else if(choice == 0)
        {
            choice2 = false;
        }
    }
        students[ind].saveStudent();

        int exx;
        System.out.print("Enter 1 to Continue & 0 to Exit : ");
        exx=input.nextInt();
        if(exx==0)
        {
            ex=false;
        }
    }


}
}
