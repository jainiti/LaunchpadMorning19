#include<iostream>
using namespace std;

void stringRotate(char ch[],int n)
{
	int len=strlen(ch);
	int j=len-1;
	while(j>=0)
	{
		ch[j+n]=ch[j];
		j--;
	}
	cout<<ch<<endl;

	int k=len;
	for(int i=0;i<n;i++)
	{
		ch[i]=ch[len+i];
	}
	cout<<ch<<endl;

	ch[len]='\0';

	cout<<ch<<endl;
}

int main()
{
	char ch[100];
	cin>>ch;

	int n;
	cin>>n;
	stringRotate(ch,n);
	// cout<<ch<<endl;
	return 0;
}
