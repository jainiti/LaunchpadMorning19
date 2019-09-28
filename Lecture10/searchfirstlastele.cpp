#include<iostream>
using namespace std;

bool searchElement(int *a,int i,int n,int key)
{
	if(i==n)
	{
		return false;
	}

	if(a[i]==key)
	{
		return true;
	}

	return searchElement(a,i+1,n,key);
}

int firstIndex(int *a,int i,int n,int key)
{
	if(i==n)
	{
		return -1;
	}

	if(a[i]==key)
	{
		return i;
	}

	return firstIndex(a,i+1,n,key);
}


int lastIndex(int *a,int i,int n,int key)
{
	if(i==n)
	{
		return -1;
	}

	if(a[i]==key)
	{
		int phelaWalaIndex=i;
		int aageKaIndex=lastIndex(a,i+1,n,key);
		if(aageKaIndex>phelaWalaIndex)
		{
			return aageKaIndex;
		}
		else
		{
			return phelaWalaIndex;
		}
	}

	return lastIndex(a,i+1,n,key);
}


int main()
{
	int n,a[1000];
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int key;
	cin>>key;
	if(searchElement(a,0,n,key))
	{
		cout<<"found"<<endl;
	}
	else
	{
		cout<<"not found"<<endl;
	}

	cout<<firstIndex(a,0,n,key)<<endl;
	cout<<lastIndex(a,0,n,key)<<endl;
	return 0;
}














