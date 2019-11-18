#include<iostream>
#include<list>
#include<map>
#include<set>

using namespace std;

template<typename T>
class Graph
{
public:
	map<T,list<pair<T,int> > >adjlist;

	void addEdge(T u,T v,int weight,bool bidir=true)
	{
		adjlist[u].push_back(make_pair(v,weight));
		if(bidir)
		{
			adjlist[v].push_back(make_pair(u,weight));
		}
	}

	void print()
	{
		for(auto node:adjlist)
		{
			cout<<node.first<<"-->";
			for(auto child:node.second)
			{
				cout<<"("<<child.first<<" "<<child.second<<") ";
			}
			cout<<endl;
		}
	}

	void SSSP(T src)
	{
		map<T,int>distance;

		for(auto node:adjlist)
		{
			distance[node.first]=INT_MAX;
		}

		distance[src]=0;
		set<pair<int,T> >s;

		s.insert(make_pair(0,src));
		while(!s.empty())
		{
			auto p=*(s.begin());
			T parent=p.second;
			int parentDistance=p.first;
			s.erase(s.begin());

			for(auto child:adjlist[parent])
			{
				if(distance[child.first]>parentDistance+child.second)
				{
					auto f=s.find(make_pair(distance[child.first],child.first));
					if(f!=s.end())
					{
						s.erase(f);
					}
					distance[child.first]=parentDistance+child.second;
					s.insert(make_pair(distance[child.first],child.first));
				}
			}

		}

		for(auto node:distance)
		{
			cout<<node.first<<" "<<node.second<<endl;
		}
	}



};

int main()
{
	Graph<char> g;
	g.addEdge('A','B',14);
	g.addEdge('A','C',2);
	g.addEdge('A','D',5);
	g.addEdge('B','D',2);
	g.addEdge('B','E',1);
	g.addEdge('C','D',6);
	g.addEdge('D','E',3);

	g.SSSP('A');
	// g.print();
	return 0;
}











