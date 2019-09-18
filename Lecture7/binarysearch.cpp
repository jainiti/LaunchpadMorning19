#include<iostream>
using namespace std;

int binarySearch(int a[],int n,int key)
{
	int s=0,e=n-1;
	while(s<=e)
	{
		int mid=(s+e)/2;

		if(a[mid]==key)
		{
			return mid;
		}
		else if(key<a[mid])
		{
			e=mid-1;
		}
		else
		{
			s=mid+1;
		}
	}

	return -1;
}

int main()
{
	int a[100];
	int n,key;
	cout<<"enter number of elements"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Enter element to be searched"<<endl;
	cin>>key;
	if(binarySearch(a,n,key)==-1)
	{
		cout<<"element absent"<<endl;
	}
	else
	{
		cout<<"element present at"<<binarySearch(a,n,key)<<"th index"<<endl;
	}
	return 0;
}






























