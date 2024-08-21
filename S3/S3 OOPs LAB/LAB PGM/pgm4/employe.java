import java.util.*;

class employee
{
	String name,phone_number,addres;
	int age,salary;
	
	Scanner sc=new Scanner(System.in);
	
	void printSalary()
	{
		System.out.println("\nSALARY         : "+salary+"\n\n");
	}
	void input()
	{
		System.out.print("Enter the name : ");
		name=sc.nextLine();
		
		System.out.print("Enter the age : ");
		age=sc.nextInt();
		
		System.out.print("Enter the Phone Number : ");
		phone_number=sc.nextLine();
		phone_number=sc.nextLine();
		
		System.out.print("Enter the address : ");
		addres=sc.nextLine();
		
		System.out.print("Enter the salary : ");
		salary=sc.nextInt();
	}
	void output()
	{
		System.out.println("NAME           : "+name);
		System.out.println("AGE            : "+age);
		System.out.println("PHONE NUMBER   : "+phone_number);
		System.out.println("ADDRESS        : "+addres);
	}
}
class officer extends employee
{
	String specialization;
	void inputO()
	{
		System.out.print("Enter the specialisation : ");
		specialization=sc.nextLine();
		specialization=sc.nextLine();
	}
	void outputO()
	{	
		System.out.print("SPECIALISATION : "+specialization);
	}
}
class manager extends employee
{
	String department;
	void inputM()
	{
		System.out.print("Enter the department : ");
		department=sc.nextLine();
		department=sc.nextLine();
	}
	void outputM()
	{
		System.out.print("DEPARTMENT     : "+department);
	}
}

public class employe
{
	public static void main(String args[])
	{
		
		officer emp1=new officer();
		manager emp2=new manager();
		
		System.out.println("Enter the details of the officer");
		emp1.input();
		emp1.inputO();
		
		System.out.println("\n\n## DETAILS OF OFFICER ##\n");
		emp1.output();
		emp1.outputO();
		emp1.printSalary();
		
		System.out.println("Enter the details of the manager");
		emp2.input();
		emp2.inputM();
		
		System.out.println("\n## DETAILS OF MANAGER ##\n");
		emp2.output();
		emp2.outputM();
		emp2.printSalary();
	}
}















