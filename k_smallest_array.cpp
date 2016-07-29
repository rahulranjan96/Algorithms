#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;
void maxHeapify(vector<int> *v,int i)
{
	int n=v->size();
	int lt=2*i+1;
	int rt=2*i+2;
	int largest=0;
	if(lt<n&&((*v)[lt]>(*v)[i]))
		largest=lt;
	else largest=i;
	if(rt<n&&((*v)[rt]>(*v)[largest]))
		largest=rt;
	if(largest!=i)
	{
		int temp=(*v)[i];
		(*v)[i]=(*v)[largest];
		(*v)[largest]=temp;
		maxHeapify(v,largest);
	}
}
void insert(vector<int> *v,int key,int k)
{
  int n=v->size();
  if(n<k)
  {
  	v->push_back(key);
  	int i=v->size()-1;
  	while(i>0&&((*v)[i/2]<(*v)[i]))
  	{
  		int temp=(*v)[i];
  		(*v)[i]=(*v)[i/2];
  		(*v)[i/2]=temp;
  		i=i/2;
  	}
  }
  else
  {
  	if(key<(*v)[0])
  		{
  			(*v)[0]=key;
  			maxHeapify(v,0);
  		}
  }
}
void print(vector<int> *v)
{
	for(int i=0;i<v->size();i++)
		cout<<(*v)[i]<<" ";
	cout<<endl;
}
int main()
{
	vector<int> A;
	int k,n;
	cout<<"Enter the value of k:";
	cin>>k;
	int key,c;
	while(1)
	{
		cout<<"1:Insert\n2:Print\n3:Exit\nEnter Choice:";
		cin>>c;
		switch(c)
		{
			case 1:cout<<"Enter the element:";
			       cin>>key;
			       insert(&A,key,k);
			       break;
			case 2:n=A.size();
			       if(n<k)
			       	cout<<"Error...Not Enough Elements Read.\n";
			       else
			       	print(&A);
			       break;
			case 3:return 0;
			default:cout<<"Please enter a vald choice.\n";
		}
	}
	return 0;
}