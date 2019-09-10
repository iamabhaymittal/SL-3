#include<stdio.h>

int main()
{
	int id;
	
	printf("\nBefore forking...!!!\n");
	
	id=fork();
	
	if(id==0)
	{
		printf("\nChild is running!!!");
		printf("\nChild's id : %d",getpid());
		printf("\nChild's Parent id : %d\n",getppid());
		//sleep(10);
		printf("\nChild is exiting\n");
		exit(0);
	}
	else
	{
		printf("\nParent is running!!!");
		printf("\nParent's id : %d",getpid());
		printf("\nParent's Parent(bash) id : %d\n",getppid());
		
		wait();
		
		printf("\nParent is exiting\n");
	}
	
	printf("\nAfter forking\n");
}
