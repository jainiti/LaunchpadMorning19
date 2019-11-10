#include<iostream>
using namespace std;

int minCoins(int coins[],int n,int amount)
{
	if(amount==0)
	{
		// dp[amount]=0;
		return 0;
	}

	int ans=INT_MAX,smallans;
	for(int i=0;i<n;i++)
	{
		if(amount>=coins[i])
		{
			smallans=minCoins(coins,n,amount-coins[i]);
		}

		if(smallans!=INT_MAX)
		{
			ans=min(ans,smallans+1);
		}
		
	}
	// dp[amount]=ans;
	return ans;
}

int bottomUp(int coins[],int n,int amount)
{
	int dp[1000];
	dp[0]=0;

	for(int i=1;i<=amount;i++)
	{
		dp[i]=INT_MAX;
	}


	for(int i=1;i<=amount;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i>=coins[j])
			{
				dp[i]=min(dp[i],1+dp[i-coins[j]]);
			}
		}
		
	}


	for(int i=0;i<=amount;i++)
	{
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	return dp[amount];
}



int main()
{
	int coins[]={1,7,10};
	int n=sizeof(coins)/sizeof(int);

	int amount;
	cin>>amount;

	cout<<minCoins(coins,n,amount)<<endl;
	return 0;
}