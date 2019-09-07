#include<iostream>
using namespace std;


int main()
{
	int n=10;
	for(int i=1;i<=n;i++)
	{
		if(i==5)
		{
			continue;
			cout<<i<<endl;
			// break;
		}
		cout<<i<<endl;
	}
	return 0;
}