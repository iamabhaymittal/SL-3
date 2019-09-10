#include<semaphore.h>
#include<stdio.h>
#include<pthread.h>
# include<bits/stdc++.h>
using namespace std;

int readcount=0,writecount=0,bsize[5];
sem_t x,y,z,rsem,wsem;
pthread_t r[10],w[10];
void *reader();
void *writer();
void * reader()
{
	while(1)
	{
		sem_wait(&z);
			sem_wait(&rsem);
				sem_wait(&x);
					readcount++;
					if(readcount==1)
						sem_wait(&wsem);
				sem_post(&x);
			sem_post(&rsem);
		sem_post(&z);
		sem_wait(&x)
			readcount--;
		if(readcount==0)
			sem_post(&wsem);
		sem_post(&x);
	}
}
