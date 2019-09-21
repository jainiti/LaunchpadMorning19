#include<iostream>
using namespace std;

void readLine(char *ch,char delimeter='\n')
{
	int i=0;
	char ch1;
	ch1=cin.get();
	while(ch1!=delimeter)
	{
		// if(i<length)
		ch[i++]=ch1;
		// i++;
		ch1=cin.get();
	}
	ch[i]='\0';
	return;
}


int main()
{
	char ch[100];
	readLine(ch);
	cout<<ch<<endl;
	return 0;
}