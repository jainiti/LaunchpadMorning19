#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a,int b)
{
	return a>b;
}


int main()
{
	int arr[]={4,3,1,6,7};
	int n=sizeof(arr)/sizeof(int);

	sort(arr,arr+n,compare);

	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}














