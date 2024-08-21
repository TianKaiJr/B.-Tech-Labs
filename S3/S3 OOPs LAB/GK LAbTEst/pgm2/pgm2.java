class oddoreven extends Thread
{
	int a,b,ch;
	oddoreven(int x,int y,int z)
	{
		a=x;
		b=y;
		ch=z;
	}
	public void run()
	{
		if(ch==1)
			odd();
		if(ch==0)
			even();
	}
	synchronized public  void odd()
	{	
		for(int i=a;i<=b;i++)
		{
			try
			{
				if((i%2)!=0)
				{
					Thread.sleep(500);
					System.out.print("ODD NUMBER = "+i+"\t");
				}
			}
			catch(Exception e)
			{
			}
			
		}
	}
	synchronized public void even()
	{	
		for(int i=a;i<=b;i++)
		{
			try
			{
				if((i%2)==0)
				{
					Thread.sleep(500);
					System.out.println("|	EVEN NUMBER = "+i);
				}
			}
			catch(Exception e)
			{
			}
		}
	}
}

public class pgm2
{
	public static void main(String args[])
	{
		oddoreven odd1=new oddoreven(1,7,1);
		oddoreven even0=new oddoreven(1,7,0);
		odd1.start();
		even0.start();
	}
}





