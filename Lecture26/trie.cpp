#include<iostream>
#include<map>
using namespace std;

class node
{
public:
	char c;
	map<char,node*>mp;
	bool isTerminal;

	node(char ch)
	{
		c=ch;
		isTerminal=false;
	}
};


class Trie
{
public:
	node* head;

	Trie()
	{
		head=new node('\0');
	}

	void insertWord(char ch[])
	{
		node* temp=head;
		for(int i=0;ch[i]!='\0';i++)
		{
			if(temp->mp.count(ch[i])==0)
			{
				node* n=new node(ch[i]);
				temp->mp[ch[i]]=n;
				temp=temp->mp[ch[i]];
			}
			else
			{
				temp=temp->mp[ch[i]];
			}
			
		}
		temp->isTerminal=true;

	}

	bool search(char ch[])
	{
		node* temp=head;
		for(int i=0;ch[i]!='\0';i++)
		{
			if(temp->mp.count(ch[i])==0)
			{
				return false;
			}
			temp=temp->mp[ch[i]];
		}

		return temp->isTerminal;
	}



};


int main()
{

	Trie t;
	t.insertWord("apple");
	t.insertWord("app");
	t.insertWord("coding");
	t.insertWord("codingBlocks");

	char ch[100];
	cin>>ch;

	if(t.search(ch))
	{
		cout<<"word found"<<endl;
	}
	else
	{
		cout<<"word not found"<<endl;
	}
	return 0;
}




