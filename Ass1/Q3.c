#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int ret, count = 0,s,n=0;

    while(1) {
        ret = fork();
        if(ret == -1)
            break;
        else if(ret == 0) {
            sleep(5);
            _exit(0);
        }
        else {
            
            count++;
             
        }
    }
  printf("max child count: %d\n", count);
      while(n<=count)
         {
           wait(NULL);
            n++;
        }
    
  
    return 0;
}