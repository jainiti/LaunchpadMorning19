#include<iostream>
using namespace std;

int* createArray()
{
	int *a=new int[10];
	for(int i=0;i<10;i++)
	{
		a[i]=9;
	}
	return a;
}

int main()
{
	int *a=new int;
	*a=1;
	cout<<*a<<endl;

	delete a;

	int *arr=new int[10];
	for(int i=0;i<10;i++)
	{
		arr[i]=i;
	}
	for(int i=0;i<10;i++)
	{
		cout<<arr[i]<<" ";
	}

	delete []arr;

	int** ptr=new int*[5];

	for(int i=0;i<5;i++)
	{
		ptr[i]=NULL;
	}

	for(int i=0;i<5;i++)
	{
       ptr[i]=new int[3];
	}

	for(int i=0;i<5;i++)
	{
		for(int j=0;j<3;j++)
		{
			ptr[i][j]=i*j;
		}
	}

	for(int i=0;i<5;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<ptr[i][j]<<" ";
		}
		cout<<endl;
	}


	for(int i=0;i<5;i++)
	{
		delete []ptr[i];
	}

	delete []ptr;

	int *crarr=createArray();
	for(int i=0;i<10;i++)
	{
		cout<<crarr[i]<<" ";
	}
	cout<<endl;
	return 0;
}









