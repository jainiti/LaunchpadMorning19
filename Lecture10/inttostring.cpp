#include<iostream>
using namespace std;

string s[]={"zero","one","two","three","four","five","six","seven","eight","nine"};

void inttostring(int n)
{
	if(n==0)
	{
		return;
	}

	int lastterm=n%10;
	inttostring(n/10);
	cout<<s[lastterm]<<" ";
}


int main()
{
	int n;
	cin>>n;

	inttostring(n);
	return 0;
}