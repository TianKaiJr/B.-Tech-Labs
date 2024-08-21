#include<stdio.h>
void main()
{
    int a[100][100],b[100][3],i,j,k=1,m,n;
    printf("Enter the rows and columns of the matrix\n");
    scanf("%d%d",&n,&m);
    
    printf("Enter the elements of the matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    
            
    printf("Inputted Sparse Matrix\n");        
    for(i=0;i<n;i++)
    {    
        for(j=0;j<m;j++)
          {  printf("%d ",a[i][j]);}
        printf("\n");
    }
    
    printf("\n");
    
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]!=0)
            {
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
                k++;
            }
        }
    }
    b[0][2]=k-1;
    b[0][0]=n;
    b[0][1]=m;
    
    printf("    Tuple Form\n");
    printf("Row Column Element\n");
    for(i=0;i<k;i++)
    {
        for(j=0;j<3;j++)
        {   
            printf("%d \t",b[i][j]);
        }
     printf("\n");
    }
    
    
    printf("Transpose of Sparse Matrix\n");
    printf("    Tuple Form\n");
    printf("Row Column Element\n");
    
    printf("%d\t%d\t%d\n",b[0][1]=m,b[0][0]=n,b[0][2]=k-1);
    
    for(i=1;i<k;i++)
    {  
        printf("%d\t%d\t%d\n",b[i][1],b[i][0],b[i][2]);
        
    }
    
}



