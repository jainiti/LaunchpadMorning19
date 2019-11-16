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
	// Graph<string>g;
	// g.addEdge("modi","yogi");
	// g.addEdge("modi","trump");
	// g.addEdge("prabhu","modi",false);
	// g.addEdge("yogi","prabhu",false);
	// g.addEdge("putin","trump",false);
	// g.addEdge("putin","modi",false);
	// g.addEdge("putin","pope",false);

	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(3,4);

	g.print();

	g.bfs(0);

	cout<<endl;
	cout<<g.SSSP(0,2)<<endl;
	return 0;
}










