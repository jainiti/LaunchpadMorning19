#include<iostream>
using namespace std;

int minSteps(int n)
{
	if(n==1)
	{
		return 0;
	}

	int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;

	op1=minSteps(n-1)+1;
	if(n%2==0)
	{
		op2=minSteps(n/2)+1;
	}

	if(n%3==0)
	{
		op3=minSteps(n/3)+1;
	}

	int ans=min(op1,min(op2,op3));
	return ans;
}

int topDown(int n,int *dp)
{
	if(n==1)
	{
		dp[n]=0;
		return dp[n];
	}

	if(dp[n]!=-1)
	{
		return dp[n];
	}

	int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;

	op1=topDown(n-1,dp)+1;
	if(n%2==0)
	{
		op2=topDown(n/2,dp)+1;
	}

	if(n%3==0)
	{
		op3=topDown(n/3,dp)+1;
	}

	int ans=min(op1,min(op2,op3));
	dp[n]=ans;
	return dp[n];
}

int bottomUp(int n)
{
	int dp[1000];
	dp[1]=0;

	for(int i=2;i<=n;i++)
	{
		int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;
		op1=dp[i-1];
		if(i%2==0)
		{
			op2=dp[i/2];
		}
		if(i%3==0)
		{
			op3=dp[i/3];
		}

		dp[i]=1+min(op1,min(op2,op3));
	}
	return dp[n];
}


int main()
{
	int n;
	cin>>n;

	int dp[1000];
	for(int i=0;i<1000;i++)
	{
		dp[i]=-1;
	}

	cout<<bottomUp(n)<<endl;
	cout<<topDown(n,dp)<<endl;
	cout<<minSteps(n)<<endl;
	return 0;
}










