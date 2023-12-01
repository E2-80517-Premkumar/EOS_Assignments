#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/msg.h>
#include<signal.h>
#define MQ_KEY 0x00001234

typedef struct message{
    long type;
    int a;
    int b;
    int c;
}message_t;
typedef struct message1{
    long type;
   // int a;
   // int b;
    int result;
}msg_t;


int main()
{
    int mqid,s,ret;

    //to create the signal
    mqid = msgget(MQ_KEY,IPC_CREAT|0600);
    if(mqid<0)
    {
        perror("message create failed!\n");
        _exit(1);
    }
    ret = fork();
    // Inside the child process
if (ret == 0) {
    message_t m1;
    // ...
    printf("Enter the num1:\n");
    scanf("%d %d", &m1.a, &m1.b); // Corrected scanf format and usage
    m1.type = 100;
    msgsnd(mqid, &m1, sizeof(message_t) - sizeof(m1.type), 0);
    msgrcv(mqid, &m1, sizeof(message_t) - sizeof(m1.type), 300, 0);
    printf("%d\n",m1.c);


    // ...

    msgctl(mqid, IPC_RMID, NULL);
}

// Inside the parent process
else {
    message_t m2;
    msg_t m3;
    msgrcv(mqid, &m2, sizeof(message_t)-sizeof(m2.type), 100, 0);
    //printf("parent: received data1: %d\n", m2.a);
    //msgrcv(mqid, &m2, sizeof(message_t)-sizeof(m2.type), 200, 0); 
    //printf("\nparent: received data2: %d\n", m2.b);
    m2.c = m2.a + m2.b;
    m2.type = 300;
    msgsnd(mqid, &m2, sizeof(message_t)-sizeof(m2.type), 0);
   // printf("%d\n",message_t);

    msgctl(mqid, IPC_RMID, NULL);
}

    return 0;
}