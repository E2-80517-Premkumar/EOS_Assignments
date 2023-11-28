#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
// one parent and Five Child
int main()
{
    int i, pid1, pid2, pid3, pid4, pid5, s1, s2, s3, s4, s5;

    pid1 = fork();
    if(pid1 == 0)
	{ // first child
        for(i=1; i<=5; i++)
		{
            printf("child 1: %d\n", i);
            sleep(1);
        }
        _exit(0);
    }

    pid2 = fork();
    if(pid2 == 0)
	{ // second child
        for(i=1; i<=5; i++)
		{
            printf("child 2: %d\n", i);
            sleep(1);
        }
        _exit(0);
    }

    pid3 = fork();
    if(pid3 == 0) 
	{ // third child
        for(i=1; i<=5; i++)
		{
            printf("child 3: %d\n", i);
            sleep(1);
        }
        _exit(0);
    }

    pid4 = fork();
    if(pid4 == 0) 
	{ // fourth child
        for(i=1; i<=5; i++)
		{
            printf("child 4: %d\n", i);
            sleep(1);
        }
        _exit(0);
    }

    pid5 = fork();
    if(pid5 == 0) 
	{ // fifth child
        for(i=1; i<=5; i++)
		{
            printf("child 5: %d\n", i);
            sleep(1);
        }
        _exit(0);
    }
    

    waitpid(pid1, &s1, 0);
    waitpid(pid2, &s2, 0);
    waitpid(pid3, &s3, 0);
    waitpid(pid4, &s4, 0);
    waitpid(pid5, &s5, 0);


    return 0;
}


