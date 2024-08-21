#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include <stdlib.h>
#include <unistd.h>
void main()
{
	int socketid,b,newsocket,len;
	char recline[100],sendline[100];
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
		printf("Message from Client = "); 
		FILE *recv=fopen("receivedS.txt","w");	
		while(1)
		{	
			read(newsocket,recline,100);
			if(recline==NULL)
				break;			
			fputs(recline,recv);
			bzero(recline,100);
		}
		fclose(recv);
		recv=fopen("received.txt","r");
		char dataToBeRead[100];
		while(fgets(dataToBeRead,50,recv)
               != NULL) {
            // Print the dataToBeRead
            printf("%s", dataToBeRead);
        }
			
		write(newsocket,recline,sizeof(recline));

		if (strcmp(recline,"quit")==0 || strcmp(sendline,"quit")== 0)
                	exit(0);
	}
	close(socketid);	
}