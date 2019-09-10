#include<stdio.h>

int main()
{
	printf("\nCurrent process id is : %d\n",getpid());
	printf("\nCurrent process parent id : %d\n",getppid());
	
	printf("\nAfter forking...");
	int id=fork();
	
	if(id!=0)
	{
		printf("\nParent process running...\n");
		printf("\nParent id : %d\n",getpid());
		printf("\nParent's parent id (bash id) : %d\n",getppid());
		sleep(1);
		printf("\nParent process exiting successfully...!!!\n");
		exit(0);	
	}
	else
	{
		printf("\nChild process running...\n");
		printf("\nChild id : %d\n",getpid());
		printf("\nChild's parent id : %d\n",getppid());
		printf("\nChild process going for sleep...!!!\n");
		sleep(5);
		printf("\nChild wakes up...!!!\n");
		printf("\nChild is now orphan\n");
		printf("\nChild id : %d\n",getpid());
		printf("\nChild's parent id : %d\n",getppid());
		
		exit(0);
	}
}
