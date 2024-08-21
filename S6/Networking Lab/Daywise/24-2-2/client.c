#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>

void main()
{
	int socketid,len;
	char sendline[100];	////////////////
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
	
	//connecting to server
	connect(socketid,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	printf("Client Connected\n");

	//////////////////// messaging
	bzero(sendline,100);
	printf("Message = ");
	gets(sendline);
	write(socketid,sendline,sizeof(sendline));
}
