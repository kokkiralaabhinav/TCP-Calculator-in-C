#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/ip.h>
#include<netinet/in.h>
#include<unistd.h>
int main()
{
    char c;
    system("clear");
    int port=9000;
    char conf;
    int cli=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in server;
    if(cli<0)
    {
        perror("\nERROR IN SOCKET CREATION");
        exit(-1);
    }
    server.sin_family=AF_INET;
    server.sin_port=htons(port);
    server.sin_addr.s_addr=INADDR_ANY;
    int b=connect(cli,(struct sockaddr*)&server,sizeof(server));
    if(b<0)
    {
        perror("\n CONNECTION FAILED");
        exit(0);
    }
    while(1)
    {
    printf("....WELCOME TO CALCULATOR....");
    printf("\n 1.UNARY OPERATION\n 2.BINARY OPERATION \n 3.EXIT");
    int choice;
    printf("\nENTER YOUR CHOICE:");
    scanf("%d",&choice);
    send(cli,&choice,sizeof(choice),0);
    if(choice==1)
    {
        printf("1.SQUARE ROOT");
        printf("\n2.SQUARE");
        printf("\n3.CUBE");
        printf("\n4.FACTORIAL");
        int opt;
        printf("\nPLEASE ENTER YOUR OPERATION:");
        scanf("%d",&opt);
        send(cli,&opt,sizeof(opt),0);
        printf("\nENTER THE NUMBER:");
        int num;
        scanf("%d",&num);
        send(cli,&num,sizeof(num),0);
    }
    else if(choice==2)
    {
        printf("1.ADDITION");
        printf("\n2.SUBTRACTION");
        printf("\n3.MULTIPLICATION");
        printf("\n4.DIVISION");
        printf("\n5.MODULUS");
        printf("\n6.POWER");
        int opt,num1,num2;
        printf("\nPLEASE ENTER YOUR OPERATION:");
        scanf("%d",&opt);
        printf("\nENTER FIRST NUMBER:");
        scanf("%d",&num1);
        printf("\nENTER SECOND NUMBER:");
        scanf("%d",&num2);
        send(cli,&opt,sizeof(opt),0);
        send(cli,&num1,sizeof(num1),0);
        send(cli,&num2,sizeof(num2),0);
    }
    else if(choice==3)
    {
        break;
        close(cli);
    }
}
}