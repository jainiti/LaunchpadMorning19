#include<iostream>
using namespace std;

void substrings(char ch1[])
{
	for(int i=0;ch1[i]!='\0';i++)
	{
		for(int j=i;ch1[j]!='\0';j++)
		{
			for(int k=i;k<=j;k++)
			{
				cout<<ch1[k];
			}
			cout<<endl;
		}
	}
}

int main()
{
	char ch1[1000];
	cin>>ch1;

	substrings(ch1);
	return 0;
}