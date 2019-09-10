#include <stdio.h>

void merge(int A[50],int low,int mid,int high,int n);
void merge_sort(int A[50],int low,int high,int n);
void bubbleSort(int A[50], int n);
void input();

void merge(int A[50],int low,int mid,int high,int n)
{
	int i=low,j=mid+1,k=low,comp_no=0,m;
	int temp[50];
	
	while(i<=mid && j<=high)
	{
		if(A[i]<=A[j])
		{
			temp[k]=A[i];
			i++;
			k++;
		}
		else
		{
			temp[k]=A[j];
			j++;
			k++;
		}
	}
	
	while(j<=high)
	{
		temp[k]=A[j];
		j++;
		k++;
	}
	
	
	while(i<=mid)
	{
		temp[k]=A[i];
		i++;
		k++;
	}
	
	for(i=low;i<=high;i++)
	{
		A[i]=temp[i];
	}
}

void merge_sort(int A[50],int low,int high,int n)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(A,low,mid,n);
		merge_sort(A,mid+1,high,n);
		merge(A,low,mid,high,n);
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

int main()
{
	printf("\nBefore forking...!!!\n");
	int n,*A,i;
	printf("\nEnter the number of integers to be sorted :- \n");
	scanf("%d",&n);
	A=(int *)malloc(sizeof(int)*n);
	printf("\nEnter the integers :- \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	printf("\nEntered integers are :- \n");
	for(i=0;i<n;i++)
	{
		printf("%d  ",A[i]);
	}
	int id;
	printf("\nAfter forking...!!!\n");
	id=fork();
	if(id!=0)
	{
		printf("\nParent process is running... \n");
		printf("\nSorting array in ascending order \n");
		merge_sort(A,0,n-1,n);
		sleep(5);
		printf("\n\nEntered integers sorted in ascending order are :- \n");
		for(i=0;i<n;i++)
		{
			printf("%d  ",A[i]);
		}
		printf("\n\nParent process exiting!!! \n");
		exit(0);
	}
	else
	{
		printf("\n\nChild process is running... \n");
		printf("\nSorting array in descending order \n");
		bubbleSort(A,n);
		wait();
		printf("\n\nEntered integers in descending order sorted manner are :- \n");
		for(i=0;i<n;i++)
		{
			printf("%d  ",A[i]);
		}
		printf("\n\nChild process exiting!!! \n");
		exit(0);
	}
}
