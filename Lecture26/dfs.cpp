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

	void dfsHelper(T src,map<T,bool> &visited)
	{
		cout<<src<<" ";
		visited[src]=true;

		for(auto child:adjlist[src])
		{
			if(!visited[child])
			{
				dfsHelper(child,visited);
			}
		}
	}

	void dfs(T src)
	{
		map<T,bool>visited;
		dfsHelper(src,visited);
		int componant=1;

		for(auto node:adjlist)
		{
			if(!visited[node.first])
			{
				componant++;
				dfsHelper(node.first,visited);
			}
		}

		cout<<"No. of componant "<<componant<<endl;
	}

};

int main()
{

	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(6,7);
	g.addEdge(6,8);
	g.addEdge(7,8);
	g.addEdge(9,10);

	g.dfs(0);
	return 0;
}










