#include<iostream>
#include<queue>

using namespace std;

void print(priority_queue<int,vector<int>,greater<int> >pq)
{
	while(!pq.empty())
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
}

int main()
{
	priority_queue<int,vector<int>,greater<int> >pq;
	int k;
	cin>>k;
	int data,count=0;
	while(1)
	{
		cin>>data;

		if(data==-1)
		{
			print(pq);
		}
		else if(count<k)
		{
			pq.push(data);
			count++;
		}

		else if(pq.top()<data)
		{
			pq.pop();
			pq.push(data);
		}

	}
	return 0;
}









