#include<iostream>
using namespace std;

int knapSack(int* wts,int *profit,int n,int capacity)
{
	if(n==0 || capacity==0)
	{
		return 0;
	}

	int inc=0,exc=0;
	
	if(capacity>=wts[n-1])
	{
		inc=profit[n-1]+knapSack(wts,profit,n-1,capacity-wts[n-1]);
	}
	exc=knapSack(wts,profit,n-1,capacity);

	return max(inc,exc);

}

int bottomUp(int *wts,int *profit,int n,int capacity)
{
	int dp[100][100]={0};

	for(int item=0;item<=n;item++)
	{
		for(int wt=0;wt<=capacity;wt++)
		{
			if(item==0 || wt==0)
			{
				dp[item][wt]=0;
			}

			int inc=0,exc=0;
			if(wt>=wts[item-1])
			{
				inc=profit[item-1]+dp[item-1][wt-wts[item-1]];
			}
			exc=dp[item-1][wt];
			dp[item][wt]=max(inc,exc);
		}
	}


	for(int item=0;item<=n;item++)
	{
		for(int wt=0;wt<=capacity;wt++)
		{
			cout<<dp[item][wt]<<" ";
		}
		cout<<endl;
	}

	return dp[n][capacity];
}

int main()
{
	int wts[]={7,4,3};
	int profit[]={15,8,8};

	int capacity;
	cin>>capacity;

	cout<<bottomUp(wts,profit,3,capacity)<<endl;
	cout<<knapSack(wts,profit,3,capacity)<<endl;
	return 0;
}