#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h> // close() warning removed

void main()
{
	//declaration of variables
	int s,len;
	char sendline[100]={""},recline[100]={""};
	struct sockaddr_in server,client;
	
	//socket creation and parameters settings
	s=socket(AF_INET,SOCK_DGRAM,0);
	server.sin_family=AF_INET;
	server.sin_port=htons(3000);
	server.sin_addr.s_addr=htonl(INADDR_ANY);
	
	//binding the socket
	bind(s,(struct sockaddr*)&server,sizeof(server));
		
	len=sizeof(client);	//size of client
	
	while(1)
	{
		// message from client
		recvfrom(s,recline,100,0,(struct sockaddr*)&client,&len); 
		if(strcmp(recline,"quit")==0 || strcmp(sendline,"quit")==0)
			exit(0);
		printf("(from Client) Message = %s\n",recline);
		// message to client
		printf("	(to Client) Message = ");
		gets(sendline);
		sendto(s,sendline,sizeof(sendline),0,(struct sockaddr*)&client,sizeof(client));
		if(strcmp(sendline,"quit")==0 || strcmp(recline,"quit")==0)
			exit(0);
	}
	
	close(s);
}
