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

bool pallindrome(char *ch)
{
	int i=0;
	int j=length(ch)-1;

	while(i<=j)
	{
		if(ch[i]!=ch[j])
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int main()
{
	char ch[1000];
	cin>>ch;
	if(pallindrome(ch))
	{
		cout<<"yes it is"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}









