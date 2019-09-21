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

void concat(char *a,char *b)
{
	int len=length(a);
	// int i=len;
	int j;
	for(j=0;b[j]!='\0';j++)
	{
		a[len+j]=b[j];
	}
	a[len+j]='\0';
}

int main()
{
	char A[100];
	cin>>A;
	char B[100];
	cin>>B;
	concat(A,B);
	cout<<A<<endl;
	return 0;
}