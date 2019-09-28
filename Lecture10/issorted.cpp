#include<iostream>
using namespace std;

bool isSorted(int *a,int n)
{
	if(n==0 || n==1)
	{
		return true;
	}

	bool kyaChotaSortedHai=isSorted(a+1,n-1);
	if(a[0]<=a[1] && kyaChotaSortedHai)
	{
		return true;
	}
	return false;
}


bool isSorted1(int *a,int i,int n)
{
	if(i==n-1)
	{
		return true;
	}

	bool kyaChotaSortedHai=isSorted1(a,i+1,n);
	if(a[i]<=a[i+1] && kyaChotaSortedHai)
	{
		return true;
	}
	return false;
}

int main()
{
	int n;
	cin>>n;
	int a[10000];

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	if(isSorted(a,n))
	{
		cout<<"yes sorted"<<endl;
	}
	else
	{
		cout<<"unsorted"<<endl;
	}

	if(isSorted1(a,0,n))
	{
		cout<<"yes sorted"<<endl;
	}
	else
	{
		cout<<"unsorted"<<endl;
	}
	return 0;
}






















