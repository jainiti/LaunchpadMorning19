#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;

	for(int row=n;row>=1;row--)
	{
		char ch='A';
		for(int col=1;col<=row;col++)
		{
			cout<<ch;
			ch++;
		}

		ch=ch-1;
		for(int col=1;col<=row;col++)
		{
			cout<<ch;
			ch--;
		}

		cout<<endl;

	}
	return 0;
}













