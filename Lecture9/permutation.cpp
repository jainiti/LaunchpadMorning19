#include<iostream>
using namespace std;

bool isPermutation(char ch1[],char ch2[])
{
	int freq[26]={0};
	for(int i=0;ch1[i]!='\0';i++)
	{
		int index=ch1[i]-'a';
		freq[index]++;
	}

	for(int i=0;ch2[i]!='\0';i++)
	{
		int index=ch2[i]-'a';
		freq[index]--;
	}

	for(int i=0;i<26;i++)
	{
		if(freq[i])
		{
			return false;
		}
	}
	return true;
}


int main()
{
	char ch1[1000],ch2[1000];
	cin>>ch1>>ch2;

	if(isPermutation(ch1,ch2))
	{
		cout<<"yes"<<endl;
	}
	else
	{
		cout<<"no"<<endl;
	}

	return 0;
}