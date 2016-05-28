#include<stdio.h>
#include<stdlib.h>

unsigned long long int a[100];

unsigned long long int fib(unsigned long long int n)
{
   if(n<=1)
   	return n;
   else{
   	if(a[n-2]!=-1&&a[n-1]==-1)
   		a[n]=fib(n-1)+a[n-2];
   	else if(a[n-2]==-1)
   		a[n]=fib(n-1)+fib(n-2);
   	else if(a[n-1]!=-1)
   		a[n]=a[n-1]+a[n-2];
   	return a[n];
    }
}

int main()
{
	unsigned long long int i=0;
	for(i=0;i<100;i++)
		a[i]=-1;
	a[0]=0;
	a[1]=1;
	unsigned long long int n=0;
	printf("Enter the ith number whose fibonacci value is to be found(i<94):");
	scanf("%llu",&n);
	unsigned long long int val=fib(n);
	printf("%lluth fibonacci number is %llu.\n",n,val);
	return 0;
}