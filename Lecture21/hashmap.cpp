#include<iostream>
using namespace std;

class node
{
public:
	string key;
	int value;
	node* next;

	node(string key,int value)
	{
		this->key=key;
		this->value=value;
		next=NULL;
	}
};

class hashMap
{
	// int hashfn(string key)
	// {
	// 	int index=0;
	// 	int mult=13;
	// 	for(int i=0;i<key.length();i++)
	// 	{
	// 		int value=mult*key[i];
	// 		index+=value;
	// 		mult*=13;

	// 		index%=ms;
	// 		mult%=ms;
	// 	}

	// 	// index%=ms;
	// 	return index;

	// }

	void rehash()
	{
		node** oldbucket=bucket;
		int oldsize=ms;

		ms*=2;
		bucket=new node*[ms];

		for(int i=0;i<ms;i++)
		{
			bucket[i]=NULL;
		}

		for(int i=0;i<oldsize;i++)
		{
			if(oldbucket[i])
			{
				node* head=oldbucket[i];
				while(head)
				{
					insert(head->key,head->value);
					head=head->next;
				}

				delete oldbucket[i];
			}
		}

		delete []oldbucket;
	}

	public:
		node** bucket;
		int cs;
		int ms;

		hashMap(int n)
		{
			bucket=new node*[n];
			cs=0;
			ms=n;

			for(int i=0;i<n;i++)
			{
				bucket[i]=NULL;
			}
		}

		int hashfn(string key)
		{
			int index=0;
			int mult=13;
			for(int i=0;i<key.length();i++)
			{
				int value=mult*key[i];
				index+=value;
				mult*=13;

				index%=ms;
				mult%=ms;
			}

			// index%=ms;
			return index;

		}


		void insert(string key,int value)
		{
			int index=hashfn(key);
			node* temp=bucket[index];

			int flag=0;
			while(temp)
			{
				if(temp->key==key)
				{
					flag=1;
					break;
				}
				temp=temp->next;
			}
	
			if(flag!=1)
			{
				node* n=new node(key,value);
				n->next=bucket[index];
				bucket[index]=n;

				// if(bucket[index]==NULL)
				// {
				// 	bucket[index]=n;
				// }
				// else
				// {
				// 	n->next=bucket[index];
				// 	bucket[index]=n;
				// }
				cs++;
			}	

			float loadFactor = cs/(ms*1.0);
			if(loadFactor>0.7)
			{
				rehash();
			}

		}

		void print()
		{
			for(int i=0;i<ms;i++)
			{
				if(bucket[i])
				{
					node* head=bucket[i];
					while(head)
					{
						// cout<<"here"<<endl;
						cout<<head->key<<" "<<head->value<<" ";
						head=head->next;
					}
					cout<<endl;
				}
			}
		}

		node* search(string key)
		{
			int index=hashfn(key);

			if(bucket[index])
			{
				node* head=bucket[index];
				while(head)
				{
					if(head->key==key)
					{
						return head;
					}
					head=head->next;
				}
			}

			return NULL;
		}

		int& operator[](string key)
		{
			node* temp=search(key);

			if(!temp)
			{
				int garbage;
				insert(key,garbage);

				node* n=search(key);
				return n->value;
			}

			if(temp)
			{
				return temp->value;
			}
		}
};


int main()
{
	hashMap mp(5);
	mp.insert("apple",100);
	mp.insert("orange",250);
	mp.insert("cherry",500);
	mp.insert("banana",50);
	mp.insert("apple",400);

	mp["papaya"]=300;
	mp["apple"]=700;
	// mp.insert("")

	mp.print();
	return 0;
}







