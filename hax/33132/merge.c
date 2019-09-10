/*
 ============================================================================
 Name        : merge.c
 Author      : Shreeya
 Roll no.    : 23171
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

static int it_no=0;

void merge(int A[50],int low,int mid,int high,int n);
void merge_sort(int A[50],int low,int high,int n);

int main(void)
{
	int n,*A,i;
	printf("Enter the number of integers to be sorted :- ");
	scanf("%d",&n);
	A=(int *)malloc(sizeof(int)*n);
	printf("\nEnter the integers :- ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	printf("\nEntered integers are :- (");
	for(i=0;i<n;i++)
	{
		printf("%d,",A[i]);
	}
	printf(")");
	merge_sort(A,0,n-1,n);
	printf("\n\nEntered integers in sorted manner are :- (");
	for(i=0;i<n;i++)
	{
		printf("%d,",A[i]);
	}
	printf(")");
	return EXIT_SUCCESS;
}

void merge(int A[50],int low,int mid,int high,int n)
{
	int i=low,j=mid+1,k=low,comp_no=0,m;
	int temp[50];
	it_no++;
	while(i<=mid && j<=high)
	{
		if(A[i]<=A[j])
		{
			temp[k]=A[i];
			i++;
			k++;
			comp_no++;
		}
		else
		{
			temp[k]=A[j];
			j++;
			k++;
			comp_no++;
		}
	}
	while(j<=high)
	{
		temp[k]=A[j];
		j++;
		k++;
		comp_no++;
	}
	
	
	while(i<=mid)
	{
		temp[k]=A[i];
		i++;
		k++;
		comp_no++;
	}
	for(i=low;i<=high;i++)
	{
		A[i]=temp[i];
	}
	printf("\n\nIteration number : %d",it_no);
	printf("\nNumber of comparisons : %d",comp_no);
	printf("\nThe numbers are arranged currently as : (");
	for(m=0;m<n;m++)
	{
		printf("%d,",A[m]);
	}
	printf(")");
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
