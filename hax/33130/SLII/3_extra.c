#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
int no,x;
int t=1;
void *fact1(void *arg)
{
	int *lhargs,low,high,thread_no,i,z;
	long int ret_value=1;
	lhargs=(int *)arg;
	low=lhargs[0];
	high=lhargs[1];
	thread_no=lhargs[2];
	printf("\n\tThread No %d joined",thread_no);
	for(i=low;i<=high;i++)
	{
		ret_value = ret_value*(i) ;
		printf("\n%d - Thread No %d - Calculated %d x %d = %ld ",t,thread_no,(ret_value)/i,i,ret_value);
		z=rand()%10;
		printf("\n%d - Thread No %d Paused -- Sleeping for %d units",t, thread_no,z);
		sleep(z);
		printf("\n%d - Thread No %d .......Resumed",t, thread_no);
		t++;
	}
	printf("\n...........Thread No %d............................exits", thread_no);
	pthread_exit((void *) ret_value);	
}
int main()
{
	int i,j,k=0,fact=1,*status;
	pthread_t P[4];
	long int c[4];
	int lhargs[3];
	printf("Enter no to find factorial:");
	scanf("%d",&no);
	x=no/4;
	for(i=0;i<4;i++)
	{
		if(i<3)
		{
			lhargs[0]=x*i+1;
			lhargs[1]=x*(i+1);
			lhargs[2]=i+1;
	        	
		}
		else
		{
			lhargs[0]=x*i+1;
			lhargs[1]=no;
			lhargs[2]=i+1;
	        	
		}
		if(pthread_create(&P[i],NULL,fact1,lhargs)!=0)
				printf(" Cannot create thread.\n");
			else
			{
				printf(" \nThread no %d created\n",i+1);
				printf("going in fact\n");
				sleep(2);
                        }
	}
	for(i=0;i<4;i++) 
        {
                       
				if(pthread_join(P[i],(void **) &status) != 0)
					perror("\nThread join failed.\n");
				c[i] = (long int)status;
	}
	printf("Factorial is :");
	for(i=0;i<4;i++)
	{
		fact=fact*c[i];
	}
	printf("%d",fact);
		
}
