#include<iostream>
using namespace std;

int elephantWays(int n,int m)
{
	if(n==0&&m==0)
	{
		return 1;
	}

	if(n<0 || m<0)
	{
		return 0;
	}

	int ans=0;
	for(int k=1;k<=n;k++)
	{
		ans+=elephantWays(n-k,m);
	}

	for(int k=1;k<=m;k++)
	{
		ans+=elephantWays(n,m-k);
	}

	return ans;
}

int bottomUp(int n,int m)
{
	int dp[100][100]={0};

	dp[0][0]=1;
	int k=1;
	for(int j=1;j<=m;j++)
	{
		dp[0][j]=k;
		k*=2;
	}

	k=1;
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=k;
		k*=2;
	}


	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int m=1;m<=i;m++)
			{
				dp[i][j]+=dp[i-m][j];
			}

			for(int m=1;m<=j;m++)
			{
				dp[i][j]+=dp[i][j-m];
			}
		}
	}

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	return dp[n][m];
}

int main()
{
	int n,m;
	cin>>n>>m;

	cout<<bottomUp(n,m)<<endl;
	cout<<elephantWays(n,m)<<endl;
	return 0;
}