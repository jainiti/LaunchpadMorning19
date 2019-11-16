#include<iostream>
#include<map>
#include<list>
#include<queue>

using namespace std;

template<typename T>
class Graph
{
public:
	int v;
	map<T,list<T> >adjlist;

	void addEdge(T u,T v,bool bidir=true)
	{
		adjlist[u].push_back(v);
		if(bidir)
		{
			adjlist[v].push_back(u);
		}

	}

	void print()
	{
		for(auto node:adjlist)
		{
			cout<<node.first<<"--> ";
			for(auto child:node.second)
			{
				cout<<child<<" ";
			}
			cout<<endl;
		}
	}

	void bfs(T src)
	{
		map<T,bool>visited;
		for(auto node:adjlist)
		{
			visited[node.first]=false;
		}

		queue<T>q;
		q.push(src);
		visited[src]=true;

		while(!q.empty())
		{
			T top=q.front();
			q.pop();

			cout<<top<<" ";
			for(auto child:adjlist[top])
			{
				if(!visited[child])
				{
					q.push(child);
					visited[child]=true;
				}
			}
		}
	}

	int SSSP(T src,T dest)
	{
		map<T,int>distance;
		map<T,T>parent;		

		for(auto node:adjlist)
		{
			distance[node.first]=INT_MAX;
		}
		distance[src]=0;
		queue<T>q;

		parent[src]=src;
		q.push(src);

		while(!q.empty())
		{
			T top=q.front();
			q.pop();

			for(auto child:adjlist[top])
			{
				if(distance[child]==INT_MAX)
				{
					distance[child]=distance[top]+1;
					q.push(child);
					parent[child]=top;
				}
			}
		}

		for(auto i:distance)
		{
			cout<<i.first<<"-->"<<i.second<<endl;
		}

		cout<<"path is"<<endl;
		T temp=dest;
		while(temp!=src)
		{
			cout<<temp<<" <-- ";
			temp=parent[temp];
		}
		cout<<src<<endl;
		cout<<"shortest distance is: ";
		return distance[dest];
	}



};

int main()
{	
	Graph<int>g;

	int board[50] = {0};  
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17]=-13;  
	board[20] = -14;
	board[24] = -8;
	board[25] = -10;
	board[32] = -2;
	board[34] = -22;

	for(int u=0;u<=36;u++)
	{
		for(int dice=1;dice<=6;dice++)
		{
			int v=u+dice+board[u+dice];
			g.addEdge(u,v,false);
		}
	}	

	cout<<g.SSSP(0,36)<<endl;

	return 0;
}










