#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

#define buff_size 10

int item=1;

typedef struct
{
	int in,out;
	sem_t full,empty;
	int buffer[buff_size];
	pthread_mutex_t lock;
}BUFFER;

BUFFER b1;

void *producer(void *num)
{
	int i,z,value;
	
	i=*(int *)num;
	
	printf("\nProducer %d preparing to produce!!!\n",i);
	
	while(1)
	{
		z=(rand()%10)+1;
		sleep(z);
		
		sem_wait(&b1.empty);
		sem_getvalue(&b1.empty,&value);
		
		if(value==0)
		{
			printf("\n<<<BUFFER FULL!!!>>> Producer %d waiting for consumer to consume!\n",i);
		}
		pthread_mutex_lock(&b1.lock);
		printf("\nPRODUCER %d produced item %d\n",i,item);
		b1.buffer[(b1.in++)%buff_size]=item++;
		pthread_mutex_unlock(&b1.lock);
		
		sem_post(&b1.full);
	}
}

void *consumer(void *num)
{
	int i,z,value,cons=1;
	
	i=*(int *)num;
	
	printf("\n\t\tConsumer %d preparing to consume!!!\n",i);
	
	while(1)
	{
		z=(rand()%10)+1;
		sleep(z);
		
		sem_wait(&b1.full);
		sem_getvalue(&b1.empty,&value);
		
		if(value==buff_size)
		{
			printf("\n<<<BUFFER EMPTY!!!>>> Consumer %d waiting for producer to produce!\n",i);
		}
		pthread_mutex_lock(&b1.lock);
		
		cons=b1.buffer[(b1.out++)%buff_size];
		printf("\n\t\tCONSUMER %d consumed item %d\n",i,cons);
		
		pthread_mutex_unlock(&b1.lock);
		
		sem_post(&b1.empty);
	}
}

void init()
{
	b1.in=0;
	b1.out=0;
	
	sem_init(&b1.empty,0,buff_size);
	sem_init(&b1.full,0,0);
	
	pthread_mutex_init(&b1.lock,NULL);
}

int main(int argc,char *argv[])
{
	int i,np,nc;
	pthread_t p_id[buff_size],c_id[buff_size];
	
	int c[]={1,2,3,4,5,6,7,8,9,10};
	
	printf("\nEnter the total number of PRODUCERS : ");
	scanf("%d",&np);
	
	printf("\nEnter the total number of CONSUMERS : ");
	scanf("%d",&nc);
	
	init();
	
	for(i=0;i<np;i++)
	{
		pthread_create(&p_id[i],NULL,*producer,&c[i]);
		printf("\n-----------------Thread created for PRODUCER %d---------------\n",i+1);
	}
	
	for(i=0;i<nc;i++)
	{
		pthread_create(&c_id[i],NULL,*consumer,&c[i]);
		printf("\n~~~~~~~~~~~~~~~~~Thread created for CONSUMER %d~~~~~~~~~~~~~~~\n",i+1);
	}
	
	for(i=0;i<np;i++)
	{
		pthread_join(p_id[i],NULL);
		printf("\n-----------------Thread no %d of producer joined at the end---------------\n",i);
	}
	
	for(i=0;i<nc;i++)
	{
		pthread_join(c_id[i],NULL);
		printf("\n-----------------Thread no %d of consumer joined at the end---------------\n",i);
	}
	
	return 0;
	
}
