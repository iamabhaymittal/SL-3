/*
	DINING PHILOSOPHER'S PROBLEM 
	-- DEADLOCK FREE SOLUTION
*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

#define THINKING 0
#define HUNGRY 1
#define EATING 2

sem_t* s;
sem_t mutex;
int* state;
int n;

void init();
void test(int);
void putdown(int);
void pickup(int);
void*phil(void*);

int main(){
	int i,*c;
	pthread_t* threads;	
	printf("ENTER NUMBER OF PHILOSOPHERS :: ");
	scanf("%d",&n);
	init();
	
	threads = (pthread_t*)malloc(n*sizeof(pthread_t));
	state = (int*)malloc(n*sizeof(int));
	c=(int*)malloc(n*sizeof(int));
	
	for(i=0;i<n;i++){
		c[i]=i;
		state[i]=THINKING;
	}
	
	for(i=0;i<n;i++){
		pthread_create(&threads[i],NULL,phil,&c[i]);
		printf("\n---------- PHILOSOPHER %d IS THINKING ----------\n",i+1);
	}
	
	for(i=0;i<n;i++){
		pthread_join(threads[i],NULL);
	}
	
return 0;
}

void init(){
	int i;
	s = (sem_t*)malloc(n*sizeof(sem_t));
	for(i=0;i<n;i++)
		sem_init(&s[i],0,1);
	sem_init(&mutex,0,1);
}

void test(int i){
	if(state[(i+1)%n]!=EATING && state[i]==HUNGRY && state[(i+n-1)%n]!=EATING){
		state[i]=EATING;
        sem_post(&s[i]);
	}
}

void check(int i){
	if(state[(i+1)%n]!=EATING && state[i]==HUNGRY && state[(i+n-1)%n]!=EATING){
        sem_post(&s[i]);
	}
}

void putdown(int i){
	sem_wait(&mutex);
	
	if(state[i]==EATING){
		state[i]=THINKING;
		printf("\n---------- PHILOSOPHER %d IS PUTTING CHOPSTICK %d AND %d DOWN ----------\n",i+1,i+1,((i+1)%n)+1);
	}
	check((i+n-1)%n);
	check((i+1)%n);
	
	sem_post(&mutex);
}

void pickup(int i){
	sem_wait(&mutex);
	
	//printf("\n---------- PHILOSOPHER %d IS HUNGRY ----------\n",i+1);
	state[i] = HUNGRY;
	test(i);
	
	if(state[i]==EATING){
		printf("\n---------- PHILOSOPHER %d TAKES CHOPSTICK %d AND %d ----------\n",i+1,i+1,((i+1)%n)+1);
		printf("\n---------- PHILOSOPHER %d IS EATING ----------\n",i+1);
		sem_post(&mutex);
	}
	else{
		sem_post(&mutex);
		sem_wait(&s[i]);
	}
}

void *phil (void* num){
	while(1){
		int *i=num;
		sleep(rand()%5);
		pickup(*i);
		sleep(rand()%5);
		putdown(*i);
	}
}
