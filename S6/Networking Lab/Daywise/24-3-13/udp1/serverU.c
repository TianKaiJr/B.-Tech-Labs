#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<unistd.h> // close() warning removed

void main()
{
	//declaration of variables
	int s,len;
	char msg[100]={""};
	struct sockaddr_in server,client;
	
	//socket creation and parameters settings
	s=socket(AF_INET,SOCK_DGRAM,0);
	server.sin_family=AF_INET;
	server.sin_port=htons(3000);
	server.sin_addr.s_addr=htonl(INADDR_ANY);
	
	//binding the socket
	bind(s,(struct sockaddr*)&server,sizeof(server));
		
	len=sizeof(client);	//size of client
	
	recvfrom(s,msg,100,0,(struct sockaddr*)&client,&len); //socket,message,size of message,?? flag ,address of client,len of client
	
	printf("(from Client) Message = %s\n",msg);
	
	close(s);
}
