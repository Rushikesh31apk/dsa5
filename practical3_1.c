#include<stdio.h>
#include<time.h>
void accept(int a[],int n)
{
	printf("\n%d ele genarte fast:",n);
	int i;
	srand(time(0));
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
void count(int a[],int n)
{
	int i,j,b[20];
	int max=a[0];
	for(i=0;i<n;i++)
	{
		if(max<a[i])
		{
			max=a[i];
		}
	}
	int c[20];
	for(i=0;i<=max;i++)
	{
		c[i]=0;
	}
	for(i=0;i<n;i++)
	{
		c[a[i]]++;
	}
	for(i=1;i<=max;i++)
	{
		c[i]=c[i]+c[i-1];
	}
	for(i=0;i<n;i++)
	{
		c[a[i]]--;
		b[c[a[i]]]=a[i];
	}
	for(j=0;j<n;j++)
	{
		a[j]=b[j];
	}
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
	count(a,n);
	display(a,n);
}
