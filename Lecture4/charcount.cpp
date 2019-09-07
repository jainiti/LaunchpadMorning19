#include<iostream>
using namespace std;

int main()
{
	int count=0;
	char ch;
	// cin>>ch;
	ch=cin.get();
	while(ch!='$')
	{
		count++;
		// cin>>ch;
		ch=cin.get();
	}
	cout<<count<<endl;
	return 0;
}