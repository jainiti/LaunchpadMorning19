#include<iostream>
using namespace std;

int minCost(int cost[][5],int i,int j)
{
	if(i==0 &&j==0)
	{
		return cost[i][j];
	}

	if(i==0 && j>0)
	{
		return cost[i][j]+minCost(cost,i,j-1);
	}

	if(j==0 && i>0)
	{
		return cost[i][j]+minCost(cost,i-1,j);
	}

	int op1=cost[i][j]+minCost(cost,i-1,j);
	int op2=cost[i][j]+minCost(cost,i,j-1);

	return min(op1,op2);

}


int bottomUp(int cost[][5],int n,int m)
{
	int dp[4][5]={0};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i==0 && j==0)
			{
				dp[i][j]=cost[i][j];
			}

			else if(i==0 && j>0)
			{
				dp[i][j]=cost[i][j]+dp[i][j-1];
			}

			else if(j==0 && i>0)
			{
				dp[i][j]=cost[i][j]+dp[i-1][j];
			}

			else
			{
				dp[i][j]=cost[i][j]+min(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	return dp[n-1][m-1];

}







int main()
{
	int cost[][5]={{2,2,7,5,4},{1,3,4,8,9},{4,6,3,4,2},{1,4,0,0,2}};
	cout<<bottomUp(cost,4,5)<<endl;
	cout<<minCost(cost,3,4)<<endl;
	return 0;
}

















