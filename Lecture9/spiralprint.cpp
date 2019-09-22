#include<iostream>
using namespace std;

void spiralPrint(int arr[][4],int n,int m)
{
	int sr=0,er=n-1,sc=0,ec=m-1;

	while(sr<=er && sc<=ec)
	{
		for(int j=sc;j<=ec;j++)
		{
			cout<<arr[sr][j]<<" ";
		}
		sr++;

		for(int j=sr;j<=er;j++)
		{
			cout<<arr[j][ec]<<" ";
		}
		ec--;

		if(sr<=er)
		{
			for(int j=ec;j>=sc;j--)
			{
				cout<<arr[er][j]<<" ";
			}
			er--;	
		}
		
		if(sc<=ec)
		{
			for(int j=er;j>=sr;j--)
			{
				cout<<arr[j][sc]<<" ";
			}
			sc++;
		}

		
	}
}

int main()
{
	int arr[][4]={{28,30,7},
				  {4,2,0},
				  {34,21,24}};
				  // {99,78,32,53},
				  // {101,56,90,23}};

	cout<<"original matrix"<<endl;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

	spiralPrint(arr,3,4);
	cout<<endl;
	return 0;
}