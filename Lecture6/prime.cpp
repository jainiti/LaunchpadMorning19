#include<iostream>
using namespace std;

// bool checkPrime(int n)
// {
// 	for(int i=2;i<n;i++)
// 	{
// 		if(n%i==0)
// 		{
// 			return false;
// 		}
// 	}
// 	return true;
// }

bool checkPrime(int);

void printPrime(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(checkPrime(i))
		{
			cout<<i<<" ";
		}
	}
	return;
}

bool checkPrime(int n)
{
	for(int i=2;i<n;i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}


int main()
{
	int n;
	cin>>n;

	printPrime(n);

	// bool ans=checkPrime(n);
	// if(ans)
	// if(checkPrime(n))
	// {
	// 	cout<<"Prime"<<endl;
	// }
	// else
	// {
	// 	cout<<"Not prime"<<endl;
	// }
	return 0;
}













