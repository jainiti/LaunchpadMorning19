#include<iostream>
using namespace std;

int nStairs(int n,int k=3)
{
	if(n==0)
	{
		return 1;
	}

	if(n<0)
	{
		return 0;
	}

	int ans=nStairs(n-1,k)+nStairs(n-2,k)+nStairs(n-3,k);
	return ans;
}

int main()
{
	int n,k;
	cin>>n>>k;

	cout<<nStairs(n)<<endl;
	cout<<nStairs(n,k)<<endl;
	return 0;
}