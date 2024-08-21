#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

void main()
{
	int socketid,b,newsocket,len;
	char recline[100];//sendline[100];
	char sendline[100];
	struct sockaddr_in serveraddr,clientaddr;
	bzero(&serveraddr,sizeof(serveraddr));
	
	//creating socket
	socketid=socket(AF_INET,SOCK_STREAM,0);
	if(socketid<0)
		printf("Socket Cannot be created\n");
	else
		printf("Socket Created\n");

	//setting parameters of socket
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(3000);
	serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
	
	//binding socket
	bind(socketid,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	if(b<0)
		printf("Cannot bind socket\n");
	else
		printf("Socket Binded Successfully\n");	
	
	
	//listen()
	listen(socketid,10);
		
	len=sizeof(clientaddr);
	newsocket=accept(socketid,(struct sockaddr*)&clientaddr,&len);
	printf("Connection Accepted\n");
	
	
	bzero(recline,100);
	bzero(sendline,100);
	
	while(1)
	{
		//message recv from client 	
		read(newsocket,recline,100);
		if (strcmp(recline,"quit")==0 || strcmp(sendline,"quit")== 0)
                	exit(0);
		//display
		printf("String from Client = ");
		puts(recline);

		//Palindrome Checking section
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

		int len=strlen(recline);
	    	char rev[100];

	   	int end=len-1;

	    	for(int begin=0;begin<len;begin++)  //reverse  making
	    	{
	    	  rev[begin]=recline[end];
	    	  end--;
	    	}
	    	
	    	int flag = 0;
	    	for(int i=0;i<len;i++) //equality checking
	    	{
			if(recline[i]!=rev[i])
			{
			    flag=1;
			    break;
			}
	    	}

	    	char np[100]="Not Palindrome";
	    	char p[100]="Palindrome";

		// send msg to client by server
	    	if(flag==0)
	    	{
			strcpy(sendline,p);
			//printf("Result to Client = %s\n",p);
			write(newsocket,sendline,sizeof(sendline));
		} 
		else
		{
			strcpy(sendline,np);
			//printf("Result to Client = %s\n",np);
			write(newsocket,sendline,sizeof(sendline));
		}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
		if (strcmp(recline,"quit")==0 || strcmp(sendline,"quit")== 0)
                	exit(0);
	}
	close(socketid);	
}



