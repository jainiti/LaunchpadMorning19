#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int>v;
	for(int i=0;i<10;i++)
	{
		v.push_back(i);
	}

	v.pop_back();
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<endl;
	}

	return 0;
}