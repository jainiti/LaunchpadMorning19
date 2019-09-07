#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;

	for(int rows=1;rows<=n;rows++)
	{
		for(int stars=1;stars<=rows;stars++)
		{
			cout<<"*";
		}
		cout<<" ";

		for(int stars=1;stars<=n-rows+1;stars++)
		{
			cout<<"*";
		}
		cout<<" ";

		for(int stars=1;stars<=n-rows+1;stars++)
		{
			cout<<"*";
		}

		cout<<" ";

		for(int stars=1;stars<=rows;stars++)
		{
			cout<<"*";
		}

		cout<<endl;


	}
	return 0;
}









