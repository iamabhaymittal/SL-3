#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include <stdio.h> 
#include<stdlib.h>

int main()
{
	printf("\nCurrent process id is : %d\n",getpid());
	printf("\nCurrent process parent id : %d\n",getppid());
	
	printf("\nAfter forking...\n");
	int id=fork();
	
	if(id!=0)
	{
		printf("\nParent process running...\n");
		printf("\nParent id : %d\n",getpid());
		printf("\nParent's parent id (bash id) : %d\n",getppid());
		printf("\nParent process going for sleep...!!!\n");
		sleep(5);
		printf("\nParent wakes up\n");
		while(1)
		{
			
		}
		printf("\nParent process exiting successfully...!!!\n");
		exit(-1);	
	}
	else
	{
		printf("\nChild process running...\n");
		printf("\nChild id : %d\n",getpid());
		printf("\nChild's parent id : %d\n",getppid());
		printf("\nChild is exiting successfully!!!\n");
		
		exit(0);
	}
}
