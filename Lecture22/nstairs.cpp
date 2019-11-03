#include<iostream>
using namespace std;

int nstairs(int n,int k)
{
	if(n==1||n==0)
	{
		return 1;
	}

	if(n<0)
	{
		return 0;
	}

	int ans=0;
	for(int i=1;i<=k;i++)
	{
		ans+=nstairs(n-i,k);
	}

	return ans;
}

int topDown(int n,int k,int *dp)
{
	if(n==1|| n==0)
	{
		dp[n]=1;
		return dp[n];
	}

	if(n<0)
	{
		return 0;
	}

	if(dp[n]!=-1)
	{
		return dp[n];
	}

	int ans=0;
	for(int i=1;i<=k;i++)
	{
		ans+=topDown(n-i,k,dp);
	}

	dp[n]=ans;
	return dp[n];
}


int bottomUp(int n,int k)
{
	int dp[1000]={0};
	dp[0]=1;
	dp[1]=1;

	for(int i=2;i<=n;i++)
	{
		for(int steps=1;steps<=k;steps++)
		{
			if(i-steps>=0)
			{
				dp[i]+=dp[i-steps];
			}
		}
	}

	return dp[n];
}


int optimised(int n,int k)
{
	int dp[1000]={0};
	dp[0]=1;
	dp[1]=1;

	for(int i=2;i<=n;i++)
	{
		if(i-k-1>=0)
		{
			dp[i]=2*dp[i-1]-dp[i-k-1];
		}
		else
		{
			dp[i]=2*dp[i-1];
		}
	}

	return dp[n];
}

int main()
{
	int n,k;
	cin>>n>>k;

	int dp[1000];
	for(int i=0;i<=1000;i++)
	{
		dp[i]=-1;
	}

	cout<<optimised(n,k)<<endl;
	cout<<bottomUp(n,k)<<endl;
	cout<<topDown(n,k,dp)<<endl;
	cout<<nstairs(n,k)<<endl;
	return 0;
}







