import java.util.*;
import java.io.*;

public class file
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		
		try
		{
			File myfile=new File("filename.txt");
			
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
			FileWriter fwrite=new FileWriter("filename.txt");
			int num;
			System.out.print("ENTER THE STRING(numeral) TO INPUT TO FILE = ");
			num=sc.nextInt();
			fwrite.write(num);
			fwrite.close();
		}
		catch(Exception f)
		{
			System.out.println(f);
		}
		try
		{
			FileReader fread=new FileReader("filename.txt");
			int prime;
			prime=fread.read();
			fread.close();
			int flag=0;
			int m=prime/2;
			
			for(int i=2;i<=m;i++)
			{
				if((prime%i)==0)
				{
					flag=1;
				}
			}
			
			if(flag==0)
				System.out.println(prime+" is PRIME");
			else
				System.out.println(prime+" is NOT PRIME");
		}
		catch(Exception g)
		{
			System.out.println(g);
		}
		
		
	}	
}						



