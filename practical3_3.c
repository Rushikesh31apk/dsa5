#include<stdio.h>
void mergesort(int a[],int lb,int ub)
{
	if(lb<ub)
	{
		int mid=(lb+ub)/2;
		mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);			
	}
}
void merge(int a[],int lb,int mid,int ub)
{
	int i=lb;
	int j=mid+1;
	int k=lb;
	int b[ub];
	while(i<=mid && j<=ub)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i++];
		}
		else{
			b[k]=a[j++];
		}
		k++;
	}
	if(i>mid)
	{
		while(j<=ub)
		{
			b[k++]=a[j++];
		}
	}
	else{
		while(i<=mid)
		{
			b[k++]=a[i++];
		}
	}
	for(k=lb;k<=ub;k++)
	{
		a[k]=b[k];
	}	
}
void display(int a[],int n)
{
	int i;
	for( i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
 
void main()
{
int a[]={12, 11, 1, 5, 6, 7};
int n=6;
	printf("\nShow element before sorting:\n");
	display(a,n);
	mergesort(a,0,n-1);
	printf("\nShow element after sorting:\n");
	display(a,n);	
 }
