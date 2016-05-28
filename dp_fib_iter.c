#include<stdio.h>
#include<stdlib.h>


unsigned long long int fib(int n)
{
	unsigned long long int a[100];
	unsigned long long int i=0;
	a[0]=0;
	a[1]=1;
	if(n<=1)
		return n;
	for(i=2;i<=n;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	return a[n];
}


int main()
{
	unsigned long long int n=0;
	printf("Enter the ith number whose fibonacci value is to be found(i<94):");
	scanf("%llu",&n);
	unsigned long long int val=fib(n);
	printf("%lluth fibonacci number is %llu.\n",n,val);
	return 0;
}