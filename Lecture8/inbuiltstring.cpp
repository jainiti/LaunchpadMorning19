#include<iostream>
#include<cstring>
using namespace std;


int main()
{
	char a[100]="hey";
	char b[100]="there";
	cout<<strlen(a)<<endl;

	char dest[100];
	strcpy(dest,a);
	cout<<dest<<endl;

	strcat(a,b);
	cout<<a<<endl;
	return 0;
}