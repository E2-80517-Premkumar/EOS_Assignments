#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
//#include <netinet/in.h>
//#include <UNIX/ip.h>
//#include <arpa/in.h>
#include<sys/un.h>
//#define SERVER_IP   "127.0.0.1"
//#define SERVER_PORT 2809

int main() {
    int serv_fd, cli_fd, ret;
    struct sockaddr_un serv_addr, cli_addr;
    socklen_t socklen;
    char str[64];
	int num1,num2,res;
    // create server socket
    serv_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(serv_fd < 0) {
        perror("failed to create listening socket");
        _exit(1);
    }

    // assign addr to server socket
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sun_family = AF_UNIX;
    //inet_aton(SERVER_IP, &serv_addr.sin_addr);
    //serv_addr.sin_port = htons(SERVER_PORT);
	strcpy(serv_addr.sun_path,"/tmp/desd_soc");
    ret = bind(serv_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if(ret < 0) {
        perror("failed to bind address to server socket");
        _exit(2);
    }

    // listen to server socket
    listen(serv_fd, 5);

    // accept client connection
    memset(&cli_addr, 0, sizeof(cli_addr));
    socklen = sizeof(cli_addr);
    cli_fd = accept(serv_fd, (struct sockaddr*)&cli_addr, &socklen);
    if(cli_fd < 0) {
        perror("failed to accept client connection");
        _exit(3);
    }

    do {
        // read from client
        //read(cli_fd, str, sizeof(str));
		read(cli_fd,&num1,sizeof(num1));
		read(cli_fd,&num2,sizeof(num2));
        //printf("client: %s\n", str);
		printf("%d\n",num1);
		printf("%d\n",num2);
        printf("server: ");
			res = num1+num2;
			write(cli_fd,&res,sizeof(int));
       // gets(str);
	   //gets(num1);
	   //gets(num2);
       //write(cli_fd,&num1,sizeof(num1));
	   //write(cli_fd,num2,sizeof(num2));
		// write to client
        //write(cli_fd, str, sizeof(str));
    } while(strcmp(str, "bye") != 0);

    // close client connecting socket
    close(cli_fd);
    // shutdown listening socket
    shutdown(serv_fd,SHUT_RDWR);
	unlink("/tmp/desd_soc");
    return 0;
}






