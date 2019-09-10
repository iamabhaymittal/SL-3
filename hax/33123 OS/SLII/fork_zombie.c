#include<stdio.h>
int main()
{
	int id;
	printf("\nBefore fork\nprocess id is %d\n",getpid());
	id=fork();
	if(id==0)
	{
		printf("\nchild process is running\n child process id is %d\n child's parent process id is %d\n",getpid(),getppid());
		printf("\n child is now zombie");
		exit(0);
	}
	else
	{
		sleep(5);
		printf("\nparent process is running\n parent process id is %d\n parent's parent(bash) id is %d\n",getpid(),getppid());
		while(1)
		{}
		printf("\nParent process abnormally terminated\n");
                exit(-1);
	}
	printf("\nAfter fork\n");
}
