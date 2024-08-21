public class exception
{
	static int num=50;
	static void func()throws ArithmeticException // Throw and Throws
	{
		if(num>10)
			throw new ArithmeticException("Exception by Throw\n");
		else
			System.out.println("Num < 10\n");
	}
	
	public static void main(String args[])
	{
		try // Try And Catch
		{
			num=52/0;
		}
		catch(Exception e)
		{
			System.out.println("Exception Caught by Try and Catch : "+e+"\n");
		}
		
		try // Finally
		{
			try
			{
				int num=52/0;
			}
			finally
			{
				System.out.println("Finally Exception Executed");
			}
		}
		catch(Exception f)
		{
			System.out.println("Exception Caught by Try and Catch from Finally : "+f+"\n");
		}
		
		try // Exception Output Throws
		{
			exception.func();
		}
		catch(Exception g)
		{
			System.out.println("Exception Caught by Try and Catch from Throws : "+g+"\n");
		}
		
		
	}
}
