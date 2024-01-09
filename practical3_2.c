#include<stdio.h>
#include<time.h>
void accept(int a[],int n)
{
	printf("\n%d ele genrate fast:\n");
	srand(time(0));
	int i;
	for(i=0;i<n;i++)
	{
	   a[i]=rand()%10;
	}
}
void display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
void display1(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
void quick(int a[],int low,int high)
{
	
	if(low<high)
	{
		int loc=part(a,low,high);
		quick(a,low,loc-1);
		quick(a,loc+1,high);
	}
}
int part(int a[],int low,int high)
{
	int pivot,start,end,temp;
	pivot=a[low];
	start=low;
	end=high;
	while(start<end)
	{
		while(a[start]<=pivot)
		{
			start++;
		}
		while(a[end]>pivot)
		{
			end--;
		}
		if(start<end)
		{
			temp=a[start];
			a[start]=a[end];
			a[end]=temp;
		}
		
	}
	temp=a[low];
	a[low]=a[end];
	a[end]=temp;
	return end;
}
void main()
{
	int a[20],n;
	printf("enter how many element you have store in array:\n");
	scanf("%d",&n);
	accept(a,n);
	
	printf("\nshow array before sorting:\n");
	display(a,n);
	printf("\nshow array after sorting:\n");
	quick(a,0,n-1);
	display(a,n);
}
