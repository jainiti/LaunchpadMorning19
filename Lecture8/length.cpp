#include<iostream>
using namespace std;

int length(char *ch)
{
	int i;
	for(i=0;ch[i]!='\0';i++)
	{

	}
	return i;
}

int main()
{
	char ch[8]="welcome";
	cout<<length(ch)<<endl;
	return 0;
}