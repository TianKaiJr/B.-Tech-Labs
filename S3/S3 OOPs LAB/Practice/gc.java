class test
{
	String name="name";
	void print()
	{
		System.out.println(name);
	}
}

public class gc
{
	public static void main(String args[])
	{
		test ob=new test();
		System.out.println("Before using garbage collector");
		ob.print();
		
		System.out.println("After using garbage collector");
		ob.name=null;
		System.gc();
		ob.print();
		
		/*System.out.println("Using garbage collector on object");
		ob=null;
		ob.print();*/
	}
}
