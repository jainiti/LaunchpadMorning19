#include<iostream>
#include<queue>

using namespace std;

void printQueue(queue<int>q)
{
	while(!q.empty())
	{
		cout<<q.front()<<endl;
		q.pop();
	}
}

int main()
{
	queue<int>q;

	q.push(1);
	q.push(2);

	cout<<q.front()<<endl;

	for(int i=3;i<=6;i++)
	{
		q.push(i);
	}

	printQueue(q);

	// while(!q.empty())
	// {
	// 	cout<<q.front()<<endl;
	// 	q.pop();
	// }



	return 0;
}