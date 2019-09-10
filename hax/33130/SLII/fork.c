#include<stdio.h>
int main()
{
	int id;
	printf("\nBefore fork\nprocess id is %d\n",getpid());
	id=fork();
	if(id==0)
	{
		printf("\nchild process is running\n child process id is %d\n child's parent process id is %d\n",getpid(),getppid());
		sleep(3);
            	exit(0);
	}
	else
	{
		
		printf("\nparent process is running\n parent process id is %d\n parent's parent(bash) id is %d\n",getpid(),getppid());
		wait();
	}
	printf("\nAfter fork\n");
}
