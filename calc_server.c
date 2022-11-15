#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/ip.h>
#include<netinet/in.h>
#include<unistd.h>
#include<math.h>
int facto(int n)
{
    int sum=1;
    if(n==0||n==1) return 1;
    for(int i=1;i<=n;i++)
    {
        sum*=i;
    }
    return sum;
}
int power(int a ,int b)
{
    int ans=1;
    for(int i=1;i<=b;i++)
    {
        ans=ans*a;
    }
    return ans;
}
// double comp_log(double n)
// {
//      double ans=log2(n);
//      return ans;
// }
float Sqrt(int num)
{
float temp,sqrt;
sqrt=num/2;
temp=0;
while(sqrt!=temp)
{
	temp=sqrt;
	sqrt=(num/temp+temp)/2;
}
	return sqrt;
}
int main()
{
    char c;
    system("clear");
    int port=9000;
    int ser=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in server,client;
    if(ser<0)
    {
        perror("\nERROR IN SOCKET CREATION");
        exit(-1);
    }
    server.sin_family=AF_INET;
    server.sin_port=htons(port);
    server.sin_addr.s_addr=INADDR_ANY;
    int b=bind(ser,(struct sockaddr*)&server,sizeof(server));
    if(b<0)
    {
        perror("\n BIND FAILED");
        exit(0);
    }
    printf("\n....SERVER IS READY....");
    listen(ser,5);
    printf("\n...LISTENING FROM CLIENT...");
    int size=sizeof(client); 

    while(1){ 

    int cli=accept(ser,(struct sockaddr*)&cli,&size); 
    if(fork()==0){close(cli);}

    if(cli<0)
    {
        perror("\n ACCEPT FAILED");
        exit(0);
    }
    printf("\nTHE REQUEST FROM %s\n",inet_ntoa(client.sin_addr));
    while(1){
        int choice;
        recv(cli,&choice,sizeof(choice),0);
        if(choice==1)
        {
            int opt;
            recv(cli,&opt,sizeof(opt),0);
            int num;
            recv(cli,&num,sizeof(num),0);
            if(opt==1)
            {
                printf("THE SQUARE ROOT OF %d is %.2lf\n",num,Sqrt(num));
                sleep(5);
                system("clear");
                continue;
            }
            else if(opt==2)
            {
                printf("THE SQUARE OF %d is %d\n",num,num*num);
                sleep(5);
                system("clear");
                continue;
            }
            else if(opt==3)
            {
                printf("THE CUBE OF %d is %d\n",num,num*num*num);
                sleep(5);
                system("clear");
                continue;
            }
            else if(opt==4)
            {
                printf("THE FACTORIAL OF %d is %d\n",num,facto(num));
                sleep(5);
                system("clear");
                continue;
            }
            // else if(opt==5)
            // {
            //     printf("THE LOGARITHM OF %d is:%.2f",num,comp_log(num));
            //     sleep(5);
            //     system("clear");
            //     continue;
            // }
        }
        else if(choice==2)
        {
            int opt;
            recv(cli,&opt,sizeof(opt),0);
            int num1;
            recv(cli,&num1,sizeof(num1),0);
            int num2;
            recv(cli,&num2,sizeof(num2),0);

            if(opt==1)
            {
                printf("THE ADDITION OF %d AND %d IS %d\n",num1,num2,num1+num2);
                sleep(5);
                system("clear");
                continue;
            }
            else if(opt==2)
            {
                printf("THE SUBTRACTION OF %d AND %d IS %d\n",num1,num2,num1-num2);
                sleep(5);
                system("clear");
                continue;
            }
            else if(opt==3)
            {
                printf("THE MULTIPLICATION OF %d AND %d IS %d\n",num1,num2,num1*num2);
                sleep(5);
                system("clear");
                continue;
            }
            else if(opt==4)
            {
                if(num2==0)
                {
                    printf("\n...DIVISION BY 0 IS NOT POSSIBLE...\n");
                    sleep(5);
                    system("clear");
                    continue;
                }
                else
                printf("THE DIVISION OF %d AND %d IS %.2f\n",num1,num2,(float)num1/num2);
                sleep(5);
                system("clear");
                continue;
            }
            else if(opt==5)
            {
                printf("THE MODULUS OF %d AND %d IS %d\n",num1,num2,num1%num2);
                sleep(5);
                system("clear");
                continue;
            }
            else if(opt==6)
            {
                printf("%d POWER %d IS %d\n",num1,num2,power(num1,num2));
                sleep(5);
                system("clear");
                continue;
            }
        }
        else if(choice==3)
        {
            break;
            close(cli);
            close(ser);
        }
        recv(cli,&c,sizeof(c),0); 
    }
    }
}