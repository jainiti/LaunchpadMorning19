#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;

	char a[1000],currans[1000];
	int len=0;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(len<strlen(a))
		{
			strcpy(currans,a);
			len=strlen(a);
		}
	}

	cout<<currans<<" "<<len<<endl;	
	return 0;
}










