/*
 ============================================================================
 Name        : quick.c
 Author      : Vishwesh Lingayat
 Roll no.    : 23180
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char mob_no[11];
	char name[30];
	float bill_amt;
}mob_user;

void create(mob_user m[50],int n);
void display(mob_user m[50],int n);
void swap(mob_user m[50],int i,int j);
int split(mob_user m[50],int lb,int ub,int n);
void quick_sort(mob_user m[50],int lb,int ub,int n);
void display2(mob_user m[50],int it_no,int comp_no,char pivot[50],int n);

int main(void)
{
	mob_user m[50];
	int n;

	printf("Enter the number of entries you want to enter : ");
	scanf("%d",&n);

	create(m,n);
	display(m,n);

	quick_sort(m,0,n-1,n);
	printf("\n\nThe record sorted in descending order of names is :- \n");
	display(m,n);


	return EXIT_SUCCESS;
}

void create(mob_user m[50],int n)
{
	int i,p,j=1,x;

	for(i=0;i<n;i++)
		{
			x=0;
			printf("\nPlease enter the details for mobile user %d :-",i+1);
			printf("\nEnter the mobile number : ");
			scanf("%s",m[i].mob_no);
			for(p=0;p<i;p++)
			{
				if((x=strcmp(m[i].mob_no,m[p].mob_no))==0)
				{
					printf("\nPlease enter unique mobile number.");
					j=0;
					break;
				}
				else
					continue;
			}
			if(j==0)
			{
				i--;
				j=1;
				continue;
			}
			x=strlen(m[i].mob_no);
			if(x!=10)
			{
				printf("\nPlease enter valid mobile number containing 10 digits.\n");
				i--;
				continue;
			}

			fflush(0);
			printf("\nEnter the name : ");
			scanf("%s",m[i].name);

			printf("\nEnter the bill amount : ");
			scanf("%f",&m[i].bill_amt);
		}
}

void display(mob_user m[50],int n)
{
	int i;

	for(i=0;i<60;i++)
			printf("*");
		printf("\nMobile no.  Name                Bill Amount\n");
		for(i=0;i<60;i++)
			printf("*");
		for(i=0;i<n;i++)
		{
			printf("\n%-12s%-20sRs.%0.2f",m[i].mob_no,m[i].name,m[i].bill_amt);
		}
		printf("\n");
		for(i=0;i<60;i++)
			printf("*");
}

void swap(mob_user m[50],int i,int j)
{
	mob_user temp;
	temp=m[i];
	m[i]=m[j];
	m[j]=temp;
}

int split(mob_user m[50],int lb,int ub,int n)
{
	static int it_no=0;
	it_no++;
	int comp_no=0;
	int pivot=lb;
	int i=lb;
	int j=ub;
	int flag=1,check1,check2;
	char temp[50];
	strcpy(temp,m[pivot].name);
	while(flag==1)
	{
		while((check1=strcmp(m[i].name,m[pivot].name))>=0 && i<=ub)
		{
			i++;
			comp_no++;
		}

		while((check2=strcmp(m[j].name,m[pivot].name))<0)
		{
			j--;
			comp_no++;
		}

		if(i<j)
			swap(m,i,j);
		else
			flag=0;
	}
	swap(m,lb,j);
	display2(m,it_no,comp_no,temp,n);
	return j;
}

void quick_sort(mob_user m[50],int lb,int ub,int n)
{
	int check=0;

	if(lb<ub)
	{
		check=split(m,lb,ub,n);
		quick_sort(m,lb,check-1,n);
		quick_sort(m,check+1,ub,n);
	}
}

void display2(mob_user m[50],int it_no,int comp_no,char pivot[50],int n)
{
	printf("\nIteration number : %d",it_no);
	printf("\nNumber of comparisons : %d",comp_no);
	printf("\nName in Pivot : %s\n",pivot);
	display(m,n);
}
