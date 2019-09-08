#include<iostream>
using namespace std;

int main()
{
	int a[100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	a[3]=1000;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";

	}
	cout<<a[78]<<endl;
	return 0;
}