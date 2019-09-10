#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int binary_search(int A[50],int low,int high,int key)
{
	int mid;
	
	while(low<=high)
	{
		mid=(low+high)/2;
		
		if(A[mid]==key)
			return mid;
		
		else if(A[mid]>key)
			low=mid+1;
		
		else if(A[mid]<key)
			high=mid-1;
	}
	
	return -1;
	
}

int main(int argc,char *argv[])
{
	int arr[argc],key,i,n,mid;
	
	printf("\n---------------Entered into second program for searching!!!---------------\n");
	
	for(i=0;i<argc;i++)
	{
		arr[i]=atoi(argv[i]);
	}
	
	printf("\nEnter the integer to be searched : ");
	scanf("%d",&key);
	
	mid=binary_search(arr,0,argc-1,key);
	
	if(mid==-1)
	{
		printf("\nEntered integer %d not found!\n",key);
	}
	else
	{
		printf("\nEntered integer %d found at location %d in sorted array!\n",key,mid+1);
	}
	
	printf("\n--------------------Searching program ending...!!!--------------------\n");
}
