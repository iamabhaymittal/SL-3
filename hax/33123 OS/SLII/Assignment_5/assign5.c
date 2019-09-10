#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#define max(a,b) ((a>b)?a:b)

/*
	mutex -- Mutual exclusion
	full  -- Indicates number of filled slots -- Initialised to 0
	empty -- Indicates number of empty slots  -- Initialised to buff_size
*/

typedef struct{
	sem_t wrt;
	pthread_mutex_t mutex;
}sem;

sem rw;


pthread_t *readers,*writers;
int readcount,k;

void init();
void *reader(void *);
void *writer(void *);

int main(){
	
	int num_w,num_r,i,*c;
	
	printf("ENTER NO. OF WRITERS :: ");	
	scanf("%d",&num_w);
	writers=(pthread_t*)malloc(num_w*sizeof(pthread_t));
	
	printf("ENTER NO. OF READERS :: ");
	scanf("%d",&num_r);
	readers=(pthread_t*)malloc(num_r*sizeof(pthread_t));
	
	c=(int*)malloc(max(num_w,num_r)*sizeof(int));
	for(i=0;i<max(num_w,num_r);i++)
		c[i]=i+1;
	
	init();		// Initialise variables
	
	for(i=0;i<num_w;i++)
		pthread_create(&writers[i],NULL,writer,&c[i]);
	for(i=0;i<num_r;i++)
		pthread_create(&readers[i],NULL,reader,&c[i]);
		
	for(i=0;i<num_w;i++)
		pthread_join(writers[i],NULL);
	for(i=0;i<num_r;i++)
		pthread_join(readers[i],NULL);
	
return 0;
}

void init(){
	sem_init(&rw.wrt,0,1);
	k=0;
	readcount=0;
}

void *writer(void*num){
	int j;
	j=*(int*)num;
	while(1){
		printf("\n----------- WRITER :: %d WANTS TO WRITE -----------------\n",j);
		sem_wait(&rw.wrt);
		printf("\n----------- WRITER :: %d IS WRITING ---------------------\n",j);
		k++;
		printf("\nValue of 'k' is :: %d\n",k);
		sleep(rand()%10);
		sem_post(&rw.wrt);
		printf("\n----------- WRITER :: %d HAS FINISHED WRITING -----------\n",j);
	}
}

void *reader(void*num){
	
	int j;
	j=*(int*)num;
	
	while(1){
		printf("\n----------- READER :: %d WANTS TO READ -----------------\n",j);
		pthread_mutex_lock(&rw.mutex);
		readcount++;
		printf("\nREADCOUNT :: %d\n",readcount);
		if(readcount==1)	sem_wait(&rw.wrt);
		pthread_mutex_unlock(&rw.mutex);
		printf("\n----------- READER :: %d IS READING --------------------\n",j);
		printf("\nValue of 'k' is :: %d\n",k);
		sleep(rand()%10);
		pthread_mutex_lock(&rw.mutex);
		printf("\n----------- READER :: %d HAS FINISHED READING ----------\n",j);
		readcount--;
		printf("\nREADCOUNT :: %d\n",readcount);
		if(readcount==0) sem_post(&rw.wrt);
		pthread_mutex_unlock(&rw.mutex);
	}
}
