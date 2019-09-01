#include<iostream>
using namespace std;

int main()
{
	float i=1;
	int n,precision;
	cin>>n>>precision;
	float inc=1;

	int p=0;
	while(p<=precision)
	{
		while(i*i<=n)
		{
			i=i+inc;
		}
		i=i-inc;
		inc=inc/10;
		p++;
	}
	
	cout<<i<<endl;
	return 0;
}

















