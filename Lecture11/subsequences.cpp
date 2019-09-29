#include<iostream>
using namespace std;

void subSequences(char in[],char out[],int i,int j)
{
	if(in[i]=='\0')
	{
		out[j]='\0';
		cout<<out<<endl;
		return;
	}

	//consider
	out[j]=in[i];
	subSequences(in,out,i+1,j+1);

	//Not considered
	subSequences(in,out,i+1,j);
}

int main()
{
	char in[100],out[100];
	cin>>in;
	subSequences(in,out,0,0);
	return 0;
}