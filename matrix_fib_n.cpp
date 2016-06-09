#include <iostream>
using namespace std;

void mul(unsigned long long int a[2][2],unsigned long long int b[2][2])
{
unsigned long long int a00=a[0][0]*b[0][0]+a[0][1]*b[1][0];
unsigned long long int a01=a[0][0]*b[1][0]+a[0][1]*b[1][1];
unsigned long long int a10=a[1][0]*b[0][0]+a[1][1]*b[1][0];
unsigned long long int a11=a[1][0]*b[1][0]+a[1][1]*b[1][1];
 a[0][0]=a00;
 a[0][1]=a01;
 a[1][0]=a10;
 a[1][1]=a11;
}

void power(unsigned long long int a[2][2],int n)
{
unsigned long long int M[2][2]={1,1,1,0};
 for(int i=0;i<n-2;i++)
  mul(a,M);

}

unsigned long long int fib(int n)
{
 if(n==0)
  return 0;
 if(n==1)
  return 1;
unsigned long long int a[2][2]={1,1,1,0};
 power(a,n);
 return a[0][0];
}

int main()
{
int n=0;
cout<<"Enter the number:";
cin>>n;
unsigned long long int ans=fib(n);
cout<<ans<<"\n";
}
