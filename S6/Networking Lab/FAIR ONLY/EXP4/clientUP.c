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
	char sendline[100]={""},recline[100]={""};
	struct sockaddr_in server,client;
	
	//socket creation and parameters settings
	c=socket(AF_INET,SOCK_DGRAM,0);
	server.sin_family=AF_INET;
	server.sin_port=htons(3000);
	server.sin_addr.s_addr=htonl(INADDR_ANY);
	
	while(1)
	{
		// message to server
		printf("	(to Server) Message = ");
		gets(sendline);
		sendto(c,sendline,sizeof(sendline),0,(struct sockaddr*)&server,sizeof(server));
		if(strcmp(sendline,"quit")==0 || strcmp(recline,"quit")==0)
			exit(0);
		// message from server
		recvfrom(c,recline,100,0,(struct sockaddr*)&client,&len); 
		if(strcmp(sendline,"quit")==0 || strcmp(recline,"quit")==0)
			exit(0);
		printf("(from Server) Result = %s\n",recline);
	}
	
	close(c);
}
