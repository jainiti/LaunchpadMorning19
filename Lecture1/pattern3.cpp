#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int row=1;
	while(row<=n)
	{
		int space=1;
		while(space<=n-row)
		{
			cout<<" ";
			space=space+1;
		}

		int val=row;
		while(val<=2*row-1)
		{
			cout<<val;
			val=val+1;
		}

		val=2*row-2;
		while(val>=row)
		{
			cout<<val;
			val=val-1;
		}
		cout<<endl;
		row=row+1;
	}
	return 0;
}











