#include<iostream>
using namespace std;

int main()
{
	int a[]={9,0,5,3,8,1,9};
	int n= sizeof(a)/sizeof(int);

	for(int i=1;i<n;i++)
	{
		int card=a[i];
		int j;
		for(j=i-1;j>=0;j--)
		{
			if(card>a[j])
			{
				break;
			}
			a[j+1]=a[j];
		}
		a[j+1]=card;
	}


	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}