#include<iostream>
using namespace std;

int binarysearch(int *a,int key,int start,int end)
{
	//base case
	if(start>end)
	{
		return -1;
	}

	int mid=(start+end)/2;
	if(a[mid]==key)
	{
		return mid;
	}
	else if(a[mid]>key)
	{
		return binarysearch(a,key,start,mid-1);
	}
	else
	{
		return binarysearch(a,key,mid+1,end);
	}
}

int main()
{
	int n;
	cin>>n;
	int a[1000];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int key;
	cin>>key;
	cout<<binarysearch(a,key,0,n-1)<<endl;
	return 0;
}