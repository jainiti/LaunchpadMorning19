#include<iostream>
using namespace std;

void toh(int n,char source,char helper,char destination)
{
	if(n==0)
	{
		return;
	}
	toh(n-1,source,destination,helper);
	cout<<"taking "<<n<<" th disc from "<<source<<" to "<<destination<<endl;
	toh(n-1,helper,source,destination);
}

int main()
{
	int n;
	cin>>n;

	char source='A',helper='B',destination='C';
	toh(n,source,helper,destination);
	return 0;
}