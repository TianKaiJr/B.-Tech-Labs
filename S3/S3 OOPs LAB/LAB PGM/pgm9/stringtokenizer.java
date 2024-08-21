import java.util.*;

public class stringtokenizer
{
	public static void main(String args[])
	{
		String arr="1 2 3 4 5 6 7 8 9";
		StringTokenizer intarr=new StringTokenizer(arr," ");
		
		int sum=0;
		
		while(intarr.hasMoreTokens())
		{
			     int n = Integer.parseInt(intarr.nextToken());
			     System.out.println("Num: "+n);
			     sum=sum+n;
		}
		System.out.println("Sum = "+sum);
	}
}
