#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int val;
	for(int row=1;row<=n;row++)
	{
		if(row%2==0)
		{
			val=0;
		}
		else
		{
			val=1;
		}

		for(int col=1;col<=row;col++)
		{
			cout<<val<<" ";
			val=1-val;
		}
		cout<<endl;
	}
	return 0;
}












