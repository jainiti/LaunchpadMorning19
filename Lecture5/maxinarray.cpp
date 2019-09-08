#include<iostream>
using namespace std;

int main()
{
	int max=INT_MIN;
	int a[]={56,900,23,71234,90};
	int n=sizeof(a)/sizeof(int);

	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}

	cout<<max<<endl;
	return 0;
}