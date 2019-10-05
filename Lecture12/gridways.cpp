#include<iostream>
using namespace std;

int nGridWays(int i,int j)
{
	if(i==0 && j==0)
	{
		return 1;
	}

	if(i<0 || j<0)
	{
		return 0;
	}

	int ans=nGridWays(i-1,j)+nGridWays(i,j-1);
	return ans;
}

int main()
{
	int i,j;
	cin>>i>>j;

	cout<<nGridWays(i,j)<<endl;
	return 0;
}