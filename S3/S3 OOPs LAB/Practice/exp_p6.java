class Employee
{
	void display()
	{	
		System.out.println("Name of the class is 'Employee'");
	}
	void calcSalary()
	{
		System.out.println("Salary of Employee is 10000");
	}
}

class Engineer extends Employee
{
	void calcSalary()
	{
		super.calcSalary();
		System.out.println("Salary of Engineer is 20000");
	}
}

public class exp_p6
{
	public static void main(String args[])
	{
		Engineer eng=new Engineer();
		eng.display();
		eng.calcSalary();
	}
}
