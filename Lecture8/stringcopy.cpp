#include<iostream>
using namespace std;

void copy(char *destination,char *source)
{
	int i;
	for(i=0;source[i]!='\0';i++)
	{
		destination[i]=source[i];
	}
	destination[i]='\0';
}

int main()
{
	char source[100];
	cin>>source;

	char destination[1000];
	copy(destination,source);
	cout<<destination<<endl;
	return 0;
}