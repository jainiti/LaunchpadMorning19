#include<iostream>
using namespace std;

int main()
{
	char ch;
	cin>>ch;

	if(ch>='A' && ch<='Z')
	{
		cout<<"Upper case"<<endl;
	}

	else if(ch>='a' && ch<='z')
	{
		cout<<"Lower case"<<endl;
	}

	else
	{
		cout<<"Neither upper npr lower"<<endl;
	}
	return 0;
}