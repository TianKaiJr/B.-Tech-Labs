#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h> // close() warning removed

void main()
{
	//declaration of variables
	int c,len;
	char msg[100]={""};
	struct sockaddr_in server,client;
	
	//socket creation and parameters settings
	c=socket(AF_INET,SOCK_DGRAM,0);
	server.sin_family=AF_INET;
	server.sin_port=htons(3000);
	server.sin_addr.s_addr=htonl(INADDR_ANY);
	
	printf("(to Server) Message = ");
	gets(msg);
	
	sendto(c,msg,sizeof(msg),0,(struct sockaddr*)&server,sizeof(server));
	
	close(c);
}
