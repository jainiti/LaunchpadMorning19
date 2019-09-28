#include<iostream>
using namespace std;

int stringtoint(char *ch,int l)
{

	if(l==0)
	{
		return 0;
	}

	int lastTerm=ch[l-1]-'0';
	int ans=stringtoint(ch,l-1)*10+lastTerm;
	return ans;
}

int main()
{
	char ch[100];
	cin>>ch;

	int len=strlen(ch);
	cout<<stringtoint(ch,len)<<endl;
	cout<<stringtoint(ch,len)/10<<endl;
	return 0;
}