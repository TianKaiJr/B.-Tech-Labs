/*GOPIKRISHNA V
	S3 CSE A
	52
	
JAVA PGM TO FIND THE FREQUENCY OF A CHARACTER IN A STRING
*/
 
import java.util.*;

public class frequency
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.println("ENTER THE STRING");
		
		int i,f=0;
		char letter;
		String string;
		
		string=sc.nextLine();
		
		int len=string.length();
		
		System.out.println("ENTER THE CHARACTER WHOSE FREQUENCY IS TO BE FOUND");
		letter=sc.next().charAt(0);
		
		for(i=0;i<len;i++)
		{
			if(string.charAt(i)==letter)
			{
				f++;
			}
		}
		
		System.out.println("FREQUENCY OF "+letter+" IS "+f);
	}
}
		
		
		
		
