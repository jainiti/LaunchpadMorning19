#include<iostream>
#include<stack>

using namespace std;


void printStack(stack<int>s1)
{
	while(!s1.empty())
	{
		cout<<s1.top()<<endl;
		s1.pop();
	}
}

int main()
{
	stack<int>s;

	s.push(1);
	s.push(2);

	// cout<<s.top()<<endl;

	for(int i=3;i<=6;i++)
	{
		s.push(i);
	}

	// cout<<s.top()<<endl;

	printStack(s);

	// while(!s.empty())
	// {
	// 	cout<<s.top()<<endl;
	// 	s.pop();
	// }


	return 0;
}












