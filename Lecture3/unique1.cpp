#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a;
	int ans=0;
	int i=1;
	while(i<=n)
	{
		cin>>a;
		ans=ans^a;
		i++;
	}
	cout<<ans<<endl;
	return 0;
}