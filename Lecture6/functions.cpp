#include<iostream>
using namespace std;

void welcome()
{
	cout<<"welcome to coding blocks"<<endl;
	return;
}

int sum(int a=0,int b=0)
{
	int Sum=a+b;
	// return Sum;
	return a+b;
}


// void sum1(int a,int b)
// {
// 	cout<<a+b<<endl;
// 	return;
// }

int main()
{
	welcome();
	// welcome();
	// int s=sum(5,6);
	// cout<<sum(5,6)<<endl;
	// cout<<s<<endl;
	cout<<sum()<<endl;
	cout<<sum(5)<<endl;
	cout<<sum(5,6)<<endl;
	return 0;
}
























