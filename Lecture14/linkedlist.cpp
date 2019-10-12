#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;

	node(int d)
	{
		data=d;
		next=NULL;
	}
};

void insertionAtFront(node* &head,node* &tail,int d)
{
	if(head==NULL)
	{
		node* n=new node(d);
		head=n;
		tail=n;
		return;
	}
	node* n=new node(d);
	n->next=head;
	head=n;
}

void insertionAtEnd(node* &head,node* &tail,int d)
{
	if(head==NULL)
	{
		node* n=new node(d);
		head=n;
		tail=n;
		return;
	}

	node* n=new node(d);
	tail->next=n;
	tail=n;
}


void print(node* head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}

int length(node* head)
{
	int len=0;
	while(head)
	{
		len++;
		head=head->next;
	}
	return len;
}



int main()
{
	node* head=NULL;
	node* tail=NULL;

	insertionAtFront(head,tail,3);
	insertionAtFront(head,tail,2);
	insertionAtFront(head,tail,1);
	insertionAtEnd(head,tail,4);
	insertionAtEnd(head,tail,5);
	insertionAtEnd(head,tail,6);

	print(head);
	cout<<endl;
	cout<<length(head)<<endl;
	return 0;
}
















