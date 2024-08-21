/*GOPIKRISHNA V
	S3 CSE A
	52
	
JAVA PGM TO CHECK WHETHER THE STRING IS PALINDROME OR NOT 
*/
 
import java.util.*;

public class palindrome
{
	public static void main(String args[])
	{
		String word,rev = "";
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("ENTER THE STRING FOR CHECKING PALINDROME OR NOT");
		
		word = sc.nextLine();
		int len = 0,i;
		
		len = word.length();
		
		for(i = len-1;i >= 0;i--)
			rev = rev + word.charAt(i);
			
		if(word.equals(rev))
			System.out.println("PALINDROME");
		else
			System.out.println("NOT PALINDROME");
		
	}
}
		
