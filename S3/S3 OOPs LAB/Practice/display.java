import java.util.*;
import java.io.*;

public class display
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		
		try
		{
			File myfile=new File("display.txt");
			
			if(myfile.createNewFile())
			{
				System.out.println("FILE CREATED");
			}
			else
			{
				System.out.println("FILE ALREADY EXIST !!");
			}
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		
		try
		{
			FileReader fwrite=new FileReader("display.txt");
			BufferedReader buffer = new BufferedReader(fwrite);
						
			int ch=0,line=0,word=0;
			String str=buffer.readLine();
			
			 LineNumberReader linereader = new LineNumberReader(fwrite);
			 int i;
             while((i=linereader.read())!=-1)
             {
             	System.out.println((linereader.getLineNumber()+1));
             	ch++;

				//System.out.println((char)i+linereader.readLine());
			 }
             
			
			System.out.print("Characters in file = "+str.length());
			
		}
		catch(Exception f)
		{
			System.out.println(f);
		}
		
	}
}





