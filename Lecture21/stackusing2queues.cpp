#include<iostream>
#include<queue>
using namespace std;

class Stack
{
public:
	queue<int>q1,q2;
	int curr_size;

	Stack()
	{
		curr_size=0;
	}

	void push(int data)
	{
		q1.push(data);
		curr_size++;
	}

	void pop()
	{
		if(q1.empty())
		{
			return;
		}

		while(q1.size()>1)
		{
			q2.push(q1.front());
			q1.pop();
		}
		q1.pop();
		curr_size--;

		queue<int>temp;
		temp=q1;
		q1=q2;
		q2=temp;
	}

	int top()
	{
		int top=-1;
		if(!q1.empty())
		{
			while(q1.size()>1)
			{
				q2.push(q1.front());
				q1.pop();
			}

			top=q1.front();
			q2.push(q1.front());
			q1.empty();

			queue<int>temp;
			temp=q1;
			q1=q2;
			q2=temp;

		}
		return top;
	}

	int size()
	{
		return curr_size;
	}

	bool empty()
	{
		return curr_size==0;
	}

};

int main()
{
	Stack s;
	s.push(100);
	s.push(203);

	cout<<s.top()<<endl; //203
	s.pop();
	cout<<s.top()<<endl; //100
	return 0;
}






