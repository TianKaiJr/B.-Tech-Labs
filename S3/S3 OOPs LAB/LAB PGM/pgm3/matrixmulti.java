/*GOPIKRISHNA V
	S3 CSE A
	52
	
JAVA PGM TO FIND THE PRODUCT OF TWO MATRICES
*/
import java.util.*;

public class matrixmulti
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		
		int row1,row2,col1,col2,i,j,k;
		int matrix1[][]=new int[10][10];
		int matrix2[][]=new int[10][10];
		int product[][]=new int[10][10];
		
		System.out.println("Enter the row and column of the first matrix");
		row1=sc.nextInt();
		col1=sc.nextInt();
		
		System.out.println("Enter the row and column of the second matrix");
		row2=sc.nextInt();
		col2=sc.nextInt();
		
		if(col1!=row2)
			System.out.println("Product of matrix not possible");
		else
		{
			System.out.println("Enter the elements of matrix 1");
			for(i=0;i<row1;i++)
				for(j=0;j<col1;j++)
				{
					matrix1[i][j]=sc.nextInt();	
				}
			
			System.out.println("Enter the elements of matrix 2");
			for(i=0;i<row1;i++)
				for(j=0;j<col2;j++)
				{
					matrix2[i][j]=sc.nextInt();	
				}
			
			int sum=0;
			for(i=0;i<row1;i++)
				for(j=0;j<col2;j++)
				{		
					sum=0;
					for(k=0;k<row2;k++)
					{	
						sum = sum + (matrix1[i][k]*matrix2[k][j]);
					}
					product[i][j]=sum;
				}
				
			System.out.println("PRODUCT OF MATRICES \n-------------------\n");
			for(i=0;i<row1;i++)
			{
				for(j=0;j<col2;j++)
				{
					System.out.print(product[i][j]+"\t");
				}
				System.out.print("\n");
			}
		}
	}
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
