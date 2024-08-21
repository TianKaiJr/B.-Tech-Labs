import java.util.*;
import java.io.*;

public class pgm1
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		
		try
		{
			File orgf=new File("org.txt");
			if(orgf.createNewFile())
				System.out.println("FILE CREATED !!");
			else
				System.out.println("FILE ALREADY EXIST !!");
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		
		try
		{
			FileWriter fwrite=new FileWriter("org.txt");
			System.out.print("Enter Input To File 1 = ");
			String num=sc.nextLine();
			fwrite.write(num);
			fwrite.close();
			
			String copy;
			FileReader fread=new FileReader("org.txt");
			
			BufferedReader bf =new BufferedReader(new FileReader("org.txt"));
			copy=bf.read();
			fread.close();
		
			File copyf=new File("copy.txt");
			if(copyf.createNewFile())
				System.out.println("FILE 2 CREATED !!");
			else
				System.out.println("FILE 2 ALREADY EXIST !!");
		
			FileWriter fwrite2=new FileWriter("copy.txt");
			fwrite2.write(copy);
			fwrite2.close();
		
			FileReader fread2=new FileReader("copy.txt");
			String disp;
			BufferedReader bf2 =new BufferedReader(new FileReader("copy.txt"));
			disp=bf2.read();
			System.out.println("FILE COPIED CONTENT = "+disp);
			fread2.close();
		}
		catch(Exception j)
		{
			System.out.println(j);
		}
		
		
		
		
	}
}
