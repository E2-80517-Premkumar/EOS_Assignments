#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include<sys/un.h>
//#include <unix/in.h>
//#include <unix/ip.h>
//#include <arpa/unix.h>

//#define SERVER_IP   "127.0.0.1"
//#define SERVER_PORT 2809

int main() {
    int cli_fd, ret,num1,num2;
    struct sockaddr_un serv_addr,cli_addr;
    char str[64];
    // create server socket
    cli_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(cli_fd < 0) {
        perror("failed to create client socket");
        _exit(1);
    }

    // connect to server socket
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sun_family = AF_UNIX;
    //inet_aton(SERVER_IP, &serv_addr.sin_addr);
    //serv_addr.sin_port = htons(SERVER_PORT);
    strcpy(serv_addr.sun_path,"/tmp/desd_soc");
    ret = connect(cli_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if(ret < 0) {
        perror("failed to connect to server socket");
        _exit(2);
    }

    do {
        printf("client:");
		printf("Enter num1:");
		scanf("%d",&num1);
       // gets(str);
        // write to server
        write(cli_fd, &num1, sizeof(int));
		printf("Enter num2:\n");
		scanf("%d",&num2);
		write(cli_fd,&num2,sizeof(int));
        // read from server
        read(cli_fd, &num1, sizeof(int));
        printf("server: %d\n",num1);
    } while(strcmp(str, "bye") != 0);

    // close client connection
    close(cli_fd);
    return 0;
}
