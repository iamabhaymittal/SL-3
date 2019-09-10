#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int  num=0;
int part_num=0;
int t=1;

void *calc_fact(void *arg) 
{
	int i, k, initial, final, *thr_ptr, z;
	long int return_value=1; 
	thr_ptr = (int *) arg;
	initial = thr_ptr[0];
	final = thr_ptr[1];
	printf("\n\tThread No %d joined",(initial-1)/part_num + 1);
	for(i=initial;i<=final;i++)
	{
		printf("\n%d - Thread No %d - Calculated %d x %d = %d",t,(initial-1)/part_num + 1,return_value,i,return_value*i);
		return_value=return_value*i;
		z=rand()%10;
		printf("\n%d - Thread No %d Paused -- Sleeping for %d units",t, (initial-1)/part_num + 1,z);
		sleep(z);
		printf("\n%d - Thread No %d .......Resumed",t, (initial-1)/part_num + 1);
		t++;
	}
	printf("\n..............Thread No %d ........................exits", (initial-1)/part_num + 1);
	pthread_exit((void *) return_value);
}

int main()
{
	int i,x,thr_ptr[2],*status;
	long int res_arr[4],ans;
	pthread_t P[4];
	
	printf("\nEnter an integer whose factorial is to be found : ");
	scanf("%d",&num);
	
	part_num=num/4;
	
	
	
	
	for(i=0;i<4;i++)
	{
	
		printf("\nhello");
		if(i<3)
		{
			thr_ptr[0]=(part_num*i)+1;
			thr_ptr[1]=part_num*(i+1);
		}
		else
		{
			thr_ptr[0]=(part_num*i)+1;
			thr_ptr[1]=num;
		}
		
		if(pthread_create(&P[i], NULL, calc_fact,thr_ptr) != 0)
			printf("\n\tCannot create thread.\n");
		else
		{
			printf("\n\tThread No %d Created",i+1);
			sleep(2);
		}		
		
	}
	

	for(i=0;i<4;i++) 
        {
		if(pthread_join(P[i],(void **) &status) != 0)
			perror("\nThread join failed.\n");
		res_arr[i] = (long int)status;
	}
	
	ans=res_arr[0]*res_arr[1]*res_arr[2]*res_arr[3];
	
	printf("\n\nAnswer of factorial : %ld\n",ans);	
}
