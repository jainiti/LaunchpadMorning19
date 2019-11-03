#include<iostream>

#include<map>
#include<vector>
using namespace std;


int main()
{
	map<string,int>mp;
	mp["apple"]=100;

	pair<string,int>p=make_pair("orange",150);
	mp.insert(p);

	mp.insert(make_pair("apple",100));

	for(auto m:mp)
	{
		cout<<m.first<<" "<<m.second<<endl;
	}


	for(auto itr=mp.begin();itr!=mp.end();itr++)
	{
		cout<<itr->first<<" "<<itr->second<<endl;
	}


	map<string,vector<int> >m;
	m["orange"].push_back(100);
	m["orange"].push_back(200);

	for(auto itr=m.begin();itr!=m.end();itr++)
	{
		cout<<itr->first<<" ";
		for(int i=0;i<itr->second.size();i++)
		{
			cout<<itr->second[i]<<" ";
		}
		cout<<endl; 
	}

	// int arr[10]={1,2,3,4,5};
	// for(int i:arr)
	// {

	// }

	return 0;
}









