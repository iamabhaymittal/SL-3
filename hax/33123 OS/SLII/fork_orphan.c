#include<stdio.h>
int main()
{
	int id;
	printf("\nBefore fork\nprocess id is %d\n",getpid());
	id=fork();
	if(id==0)
	{
		printf("\nchild process is running\n child process id is %d\n child's parent process id is %d\n",getpid(),getppid());
		sleep(5);
		printf("\n child is now orphan");
		printf("\n Orphan's parent id is %d",getppid());
	}
	else
	{
		printf("\nparent process is running\n parent process id is %d\n parent's parent(bash) id is %d\n",getpid(),getppid());
		sleep(1);
		printf("\nParent process terminated\n");
                exit(0);
	}
	printf("\nAfter fork\n");
}
