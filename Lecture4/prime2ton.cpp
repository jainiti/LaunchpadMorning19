#include<iostream>
using namespace std;


int main()
{
	int n,num,i;
	cin>>n;


	for(num=2;num<=n;num++)
	{
		for(i=2;i<num;i++)
		{
			if(num%i==0)
			{
				break;
			}
		}
		if(i==num)
		{
			cout<<num<<" ";
		}
	}
	return 0;
}










