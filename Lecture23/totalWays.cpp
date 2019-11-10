#include<iostream>
using namespace std;

int totalWays(int n,int m)
{
	if(n==0 && m==0)
	{
		return 1;
	}

	else if(n==0 && m>0)
	{
		return 1;
	}

	else if(m==0 && n>0)
	{
		return 1;
	}

	else 
	{
		return totalWays(n-1,m)+totalWays(n,m-1);
	}

}


int bottomUp(int n,int m)
{
	int dp[100][100]={0};
	dp[0][0]=1;

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0 && j==0)
			{
				dp[i][j]=1;
			}
			else if(i==0 && j>0)
			{
				dp[i][j]=1;
			}

			else if(j==0 && i>0)
			{
				dp[i][j]=1;
			}
			else
			{
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
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
	cout<<totalWays(n,m)<<endl;
	return 0;
}