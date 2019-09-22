#include<iostream>
using namespace std;


void wavePrint(int arr[][4],int n,int m)
{
	for(int j=0;j<m;j++)
	{
		if(j%2==0)
		{
			for(int i=0;i<n;i++)
			{
				cout<<arr[i][j]<<" ";
			}
		}
		
		else
		{
			for(int i=n-1;i>=0;i--)
			{
				cout<<arr[i][j]<<" ";
			}
		}

		cout<<endl;

	}
	return;
}

int main()
{
	int arr[][4]={{28,30,7,3},
				  {4,2,0,7},
				  {99,78,32,53},
				  {101,56,90,23}};
	
	cout<<"original matrix"<<endl;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<"wave print"<<endl;
	cout<<endl;
	wavePrint(arr,4,4);
	return 0;
}













