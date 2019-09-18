#include<iostream>
using namespace std;

int sumarray(int *p,int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=*(p+i);
	}
	return sum;
}

int main()
{
	int a=10;
	cout<<&a<<endl;

	int *p=&a;
	cout<<p<<endl;
	cout<<*p<<endl;

	int arr[100]={1,2,3};
	cout<<arr+1<<endl;
	cout<<&arr[0]+1<<endl;
	cout<<&arr+1<<endl;

	cout<<sumarray(arr+2,3)<<endl;


	return 0;
}














