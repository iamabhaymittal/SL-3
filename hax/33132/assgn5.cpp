#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#include<pthread.h>
#include<semaphore.h>

using namespace std;

sem_t x,y,z,rsem,wsem;
int readcount=0,writecount=0;

void *reader()
{
	while(1)
	{
		cout<<"\n\tReader is reading!"<<endl;
		
		sem_wait(&z);
			sem_wait(&rsem);
				sem_wait(&x);
					readcount++;
					if(readcount==1)
						sem_wait(&wsem);
				sem_post(&x);
			sem_post(&rsem);
		sem_post(&z);
		
		//reading
		
		sem_wait(&x)
			readcount--;
			if(readcount==0)
				sem_post(&wsem);
		sem_post(&x);
	}
}

void *writer()
{
	while(1)
	{
		sem_wait(&y);
	}
}

int main()
{
	sem_init(&x,0,1);
	sem_init(&y,0,1);
	sem_init(&z,0,1);
	sem_init(&rsem,0,1);
	sem_init(&wsem,0,1);
}
