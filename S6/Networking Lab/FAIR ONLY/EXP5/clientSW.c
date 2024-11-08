#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void main(){
    int c,len;
    char rmsg[100],smsg[100];
    struct sockaddr_in server,client;

    int frame=0,in_frame;
    char info[100],str1[100],str2[100];
    
    c = socket(AF_INET,SOCK_DGRAM,0);
    
    server.sin_family = AF_INET;
    server.sin_port = htons(3000);
    server.sin_addr.s_addr=htonl(INADDR_ANY);

    bind(c,(struct sockaddr*)&client, sizeof(client));

    
    
    len = sizeof(server);

    while(1){

        frame ++;
        sprintf(str1,"%d",frame);

        printf("Enter frame number : ");
        gets(smsg);

    
        sendto(c,smsg,100,0,(struct sockaddr*)&server,len);
        if (strcmp(smsg,"quit")==0 || strcmp(rmsg,"quit")== 0)
        	exit(0);
        

        recvfrom(c,rmsg,100,0,(struct sockaddr*)&server, &len);
        if (strcmp(smsg,"quit")==0 || strcmp(rmsg,"quit")== 0)
        	exit(0);

        printf("Message from Sever : %s\n",rmsg);
        sscanf(rmsg,"%d",&in_frame);
        

        if (in_frame == frame){
            printf("Acknowledgment %d Recieved\n",in_frame);
        }
        else{
            frame--;
        }

    }

    close(c);
}
