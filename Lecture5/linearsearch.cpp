#include<iostream>
using namespace std;

int main()
{
	int a[]={90,45,78,24,56};
	int n=sizeof(a)/sizeof(int);

	int key;
	cin>>key;

	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			cout<<"element present"<<endl;
			break;
		}
	}

	if(i==n)
	{
		cout<<"element absent"<<endl;
	}
	return 0;
}






