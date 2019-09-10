#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

void swap(int *xp, int *yp);
void bubbleSort(int A[], int n);
#define MAX 15 

int main()
{
	int a[MAX];
	char *arg[MAX],str[MAX];
	int i,n,id,check;
	
	printf("\n    <<<Before forking...!!!>>>\n");
	printf("\nCurrent process id : %d\n",getpid());
	
	printf("\nEnter the number of integers : ");
	scanf("%d",&n);
	
	printf("\n\nEnter the integers :-\n ");
	for(i=0;i<n;i++)
	{
		printf("\nEnter integer %d : ",i+1);
		scanf("%d",&a[i]);
	}
	
	printf("\nEntered integers are : (");
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}
	printf(")\n");
	
	printf("\nSorting array of integers...\n");	
	bubbleSort(a,n);
	
	printf("\n    <<<Invoking forking...!!!>>>\n");
	
	id=fork();
	
	if(id==0)
	{
		printf("\n--------------------Child process running...!!!--------------------\n");
		printf("\nChild id is : %d\n",getpid());
		
		printf("\nSorted integers are : (");
		for(i=0;i<n;i++)
		{
			printf("%d  ",a[i]);
		}
		printf(")\n");
		
		for(i=0;i<n;i++)
		{
			sprintf(str,"%d",a[i]);
			arg[i]=(char*)malloc(sizeof(str));
			strcpy(arg[i],str);
		}
		arg[i]=NULL;
		
		printf("\nExecuting execve command!!!\n");
		check=execve("./2B2",arg,NULL);
		
		printf("\nCheck = %d",check);
		
		printf("\nControl back to child process!\n");
		printf("\nChild exiting ...!!!\n");
		exit(0);
	}
	else
	{
		printf("\n--------------------Parent process running...!!!--------------------\n");
		printf("\nParent id is : %d\n",getpid());
		
		printf("\nParent is waiting now...\n");
		wait();
		
		printf("\n\nControl back to Parent!\n");
		printf("\n--------------------Parent process exiting...!!!--------------------\n");
		exit(0);
	}	
}


void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void bubbleSort(int A[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)          
       for (j = 0; j < n-i-1; j++)  
           if (A[j] < A[j+1]) 
              swap(&A[j], &A[j+1]); 
} 

