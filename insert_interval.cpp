#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
  struct Interval {
      int start;
      int end;
  };
 
  typedef struct Interval interval;
/*
 * intervals : the array of interval
 * sz : number of entries in intervals
 * newInterval : new Interval to be inserted
 * len : populate the length of returned array of intervals in len
 */
 void swap(interval *a,interval *b)
 {
     interval temp=*a;
     *a=*b;
     *b=temp;
 }
 void maxheapify(interval *a,int n,int i)
 {
     int lt=2*i+1;
     int rt=2*i+2;
     int largest=0;
     if(lt<=n&&a[lt].start>a[i].start)
     largest=lt;
     else largest=i;
     if(rt<=n&&a[rt].start>a[largest].start)
     largest=rt;
     if(largest!=i)
     {
         swap(&a[i],&a[largest]);
         maxheapify(a,n,largest);
     }
 }
 void maxheap(interval *a,int n)
 {
     int i=0;
     for(i=n/2;i>=0;i--)
     maxheapify(a,n,i);
 }
 void heap_sort(interval *a,int n)
 {
     int i=0;
     maxheap(a,n);
     for(i=n;i>0;i--)
     {
         swap(&a[i],&a[0]);
         n--;
         maxheapify(a,n,0);
     }
 }
int min(int a,int b)
{
    if(a<=b)
     return a;
    else return b;
}
int max(int a,int b)
{
    if(a>=b) 
    return a;
    else return b;
}
interval* insert(interval *intervals, int sz, interval newInterval, int *len) {
    interval *a=(interval*)malloc((sz+1)*sizeof(interval));
    int i=0;
    a[0]=newInterval;
    if(a[0].start>a[0].end)
    {
    	int temp=a[0].start;
    	a[0].start=a[0].end;
    	a[0].end=temp;
    }
    for(i=1;i<=sz;i++)
    a[i]=intervals[i-1];
    heap_sort(a,sz);
    printf("%d\n\n",sz);
    //for(i=0;i<=sz;i++) printf("%d %d\n",a[i].start,a[i].end);
    interval *stack=(interval*)malloc((sz+1)*sizeof(interval));
    int j=1;
    stack[0]=a[0];
    for(i=1;i<=sz;i++)
    { 
        stack[j]=a[i];
     while(j>=0&&stack[j-1].end>=stack[j].start)
     {
      stack[j-1].start=min(stack[j-1].start,stack[j].start);
      stack[j-1].end=max(stack[j-1].end,stack[j].end);
      j--;
     }
     j++;
    }
    *len=j;
    
    for(i=0;i<*len;i++)
    	printf("%d %d\n",stack[i].start,stack[i].end);
    return stack;
    
    
}

int main()
{
	interval a[29]= {{6037774, 6198243}, {6726550, 7004541}, {8842554, 10866536}, {11027721, 11341296}, {11972532, 14746848}, {16374805, 16706396}, {17557262, 20518214}, {22139780, 22379559}, {27212352, 28404611}, {28921768, 29621583}, {29823256, 32060921}, {33950165, 36418956}, {37225039, 37785557}, {40087908, 41184444}, {41922814, 45297414}, {48142402, 48244133}, {48622983, 50443163}, {50898369, 55612831}, {57030757, 58120901}, {59772759, 59943999}, {61141939, 64859907}, {65277782, 65296274}, {67497842, 68386607}, {70414085, 73339545}, {73896106, 75605861}, {79672668, 84539434}, {84821550, 86558001}, {91116470, 92198054}, {96147808, 98979097} };
	interval b;
	b.start=36210193;
	b.end= 61984219;

	int x;
	insert(a,29,b,&x);
}