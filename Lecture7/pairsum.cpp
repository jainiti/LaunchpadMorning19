#include<iostream>
using namespace std;

int main()
{
	int n,a[1000],x;
	cout<<"enter number of elements"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"enter X"<<endl;
	cin>>x;

	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]+a[j]==x)
			{
				if(a[i]>a[j])
				{
					cout<<a[j]<<" "<<a[i]<<endl;
				}
				else
				{
					cout<<a[i]<<" "<<a[j]<<endl;
				}
			}
		}
	}

	return 0;
}










