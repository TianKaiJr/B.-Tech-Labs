#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#define CHAR 100 
void send_file(FILE *fp, int sockid)
{
    char data[CHAR];
	while (fgets(data,CHAR,fp)!=NULL)
	{
		if (write(sockid,data,sizeof(data))==-1)
		{
			perror("[-] Error in sending data");
            exit(1);
		}
		bzero(data,CHAR);
	}
	
}

void main()
{
	int socketid,len;
	char sendline[CHAR],recline[CHAR];
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
	
	bzero(sendline,CHAR);				
	bzero(recline,CHAR);
	
	char fname[CHAR],content[CHAR];

	while(1)
	{
		if(strcmp(recline,"quit")==0 || strcmp(sendline,"quit")==0)
                	exit(0);
		/////////////////////////////////////////////////////////////
		printf("File Name (.txt) :: ");
		scanf("%s",fname);
		FILE *fp=fopen(fname,"w");
		printf("Enter Contents to File >> ");
		scanf("%s",content);
		fputs(content,fp);
		fclose(fp);
		fp=fopen(fname,"r");
		send_file(fp,socketid);
		/////////////////////////////////////////////////////////////

		//message recv and display from server
		printf("Message from Server = ");
		FILE *recv=fopen("receivedC.txt","w");
		while (1)
		{
			read(socketid,recline,CHAR);
			printf("HHHHHH\n");
			if(recline == NULL)
				break;
			fputs(recline,recv);
			bzero(recline,CHAR);
		}
		fclose(recv);
		recv=fopen("received.txt","r");
		char dataToBeRead[CHAR];
		while(fgets(dataToBeRead,50,recv)
               != NULL) {
            // Print the dataToBeRead
            printf("%s", dataToBeRead);
        }

		
		if(strcmp(recline,"quit")==0 || strcmp(sendline,"quit")==0)
                	exit(0);		
	}
        close(socketid);
}
