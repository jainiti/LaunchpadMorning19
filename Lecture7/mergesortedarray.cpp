#include<iostream>
using namespace std;

void mergeSortedArrays(int a[],int m,int b[],int n)
{
	int i=m-1,j=n-1,k=n+m-1;
	while(i>=0 && j>=0)
	{
		if(a[i]>b[j])
		{
			a[k]=a[i];
			k--;
			i--;
		} 
		else
		{
			a[k]=b[j];
			k--;
			j--;
		}
	}

	while(j>=0)
	{
		a[k]=b[j];
		k--;
		j--;
	}
}



int main()
{
	int a[100],b[30];
	int n,m;
	cout<<"Enter number of elements in A"<<endl;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
	}

	cout<<"Enter number of elements in B"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	//merge

	mergeSortedArrays(a,m,b,n);




	for(int i=0;i<n+m;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;  
	return 0;
}



























