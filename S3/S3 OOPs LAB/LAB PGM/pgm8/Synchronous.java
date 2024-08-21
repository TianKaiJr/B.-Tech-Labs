class display
{
	synchronized public void print(String msg)
	{
		System.out.print("[" + msg);
		try
		{
			Thread.sleep(1000);
		}
		catch(Exception e)
		{
			System.out.print(e);
		}
		System.out.print("]");
	}
}

class SyncThread extends Thread
{
	display d1;
	String abc;
	
	SyncThread(display d3,String xyz)
	{
		d1 = d3;
		abc = xyz;
	}	
	
	public void run()
	{
		d1.print(abc);
	}
}

class Synchronous
{
	public static void main(String []args)
	{
		display d = new display();
		
		SyncThread t1 = new SyncThread(d,"Hello");
		SyncThread t2 = new SyncThread(d,"World");
		
		t1.start();
		t2.start();
	}
}
