#include<iostream>
using namespace std;

class Vector
{
public:
	int *arr;
	int cs;
	int ms;

	Vector(int n=1)
	{
		arr=new int[n];
		cs=0;
		ms=n;
	}


	void push_back(int value)
	{
		if(cs==ms)
		{
			int *oldarr=arr;
			arr=new int[2*ms];
			for(int i=0;i<ms;i++)
			{
				arr[i]=oldarr[i];
			}
			ms=2*ms;	
		}

		arr[cs]=value;
		cs++;
	}

	void pop_back()
	{
		if(cs>0)
		{
			cs--;
		}
	}


	int size()
	{
		return cs;
	}

	int capacity()
	{
		return ms;
	}

	bool empty()
	{
		return cs==0;
	}

	int operator[](int i)
	{
		return arr[i];
	}



};

int main()
{
	Vector v(2);
	for(int i=0;i<10;i++)
	{
		v.push_back(i);
	}

	v.pop_back();
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<endl;
	}

	// cout<<v[9]<<endl;
	return 0;
}










