#include<iostream>
using namespace std;

int maxProfit(int *profit,int i,int j,int day)
{
	if(i>j)
	{
		return 0;
	}

	int op1=profit[i]*day+maxProfit(profit,i+1,j,day+1);
	int op2=profit[j]*day+maxProfit(profit,i,j-1,day+1);

	return max(op1,op2);
}

int topDown(int profit[],int i,int j,int day,int dp[][100])
{
	if(i>j)
	{
		return 0;
	}

	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}


	int op1=profit[i]*day+topDown(profit,i+1,j,day+1,dp);
	int op2=profit[j]*day+topDown(profit,i,j-1,day+1,dp);

	dp[i][j]=max(op1,op2);
	return dp[i][j];
}

int bottomUp(int profit[],int n)
{
	int day=n;
	int dp[100][100]={0};

	for(int i=0;i<n;i++)
	{
		dp[i][i]=profit[i]*day;
	}
	day--;

	for(int len=2;len<=n;len++)
	{
		int i=0,maxi=n-len;
		while(i<=maxi)
		{
			int j=i+len-1;
			int op1=profit[i]*day+dp[i+1][j];
			int op2=profit[j]*day+dp[i][j-1];

			dp[i][j]=max(op1,op2);
			i++;
		}
		day--;
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	return dp[0][n-1];

}

int main()
{
	int profit[]={2,3,5,1,4};
	int n=sizeof(profit)/sizeof(int);

	int dp[100][100];
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{
			dp[i][j]=-1;
		}
	}

	cout<<bottomUp(profit,n)<<endl;
	cout<<topDown(profit,0,n-1,1,dp)<<endl;
	cout<<maxProfit(profit,0,n-1,1)<<endl;

	return 0;
}