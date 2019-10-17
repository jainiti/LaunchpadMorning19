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


void insertionAtPos(node* &head,node* &tail,int d,int p)
{
	if(p==0)
	{
		insertionAtFront(head,tail,d);
		return;
	}

	else if(p>=length(head))
	{
		insertionAtEnd(head,tail,d);
		return;
	}

	int pos=1;
	node* temp=head;
	node* n=new node(d);
	while(pos<p)
	{
		temp=temp->next;
		pos++;
	}

	n->next=temp->next;
	temp->next=n;
}


void deletionAtFront(node* &head,node* &tail)
{
	if(head==NULL)
	{
		return;
	}

	else if(head==tail)
	{
		delete head;
		head=NULL;
		tail=NULL;
		return;
	}

	else
	{
		node* temp=head;
		head=head->next;
		delete temp;
	}
}


void deletionAtEnd(node* &head,node* &tail)
{
	if(head==NULL)
	{
		return;
	}

	else if(head==tail)
	{
		delete head;
		head=NULL;
		tail=NULL;
	}

	else
	{
		node* temp=head;
		while(temp->next!=tail)
		{
			temp=temp->next;
		}
		temp->next=NULL;
		delete tail;
		tail=temp;
	}
}

void deletionAtPos(node* &head,node* &tail,int p)
{
	if(p==0)
	{
		deletionAtFront(head,tail);
		return;
	}
	else if(p==length(head)-1)
	{
		deletionAtEnd(head,tail);
		return;
	}

	else if(p>=length(head))
	{
		return;
	}

	else
	{
		node* temp=head;
		int pos=1;
		while(pos<p)
		{
			temp=temp->next;
			pos++;	
		}

		node* n=temp->next;
		temp->next=n->next;
		delete n;
	}
}

node* search(node* head,int d)
{
	while(head)
	{
		if(head->data==d)
		{
			return head;
		}
		head=head->next;
	}
	return NULL;
}

node* searchRec(node* head,int d)
{
	if(head==NULL)
	{
		return NULL;
	}

	if(head->data==d)
	{
		return head;
	}
	return searchRec(head->next,d);
}

node* mid(node* head)
{
	node* slow=head;
	node* fast=head->next;

	while(fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
	}

	return slow;
}


node* merge(node* headA,node* headB)
{
	if(headA==NULL)
	{
		return headB;
	}
	else if(headB==NULL)
	{
		return headA;
	}

	else
	{
		node* nhead=NULL;
		if(headA->data<headB->data)
		{
			nhead=headA;
			nhead->next=merge(headA->next,headB);
		}
		else
		{
			nhead=headB;
			nhead->next=merge(headA,headB->next);
		}
		return nhead;
	}
}

node* mergeSort(node* head)
{
	if(head==NULL || head->next==NULL)
	{
		return head;
	}


	node* m=mid(head);
	node* a=head;
	node* b=m->next;
	m->next=NULL;

	a=mergeSort(a);
	b=mergeSort(b);

	node* nhead=merge(a,b);
	return nhead;
}


node* reverseLL(node* head)
{
	node* curr=head;
	node* prev=NULL;

	while(curr)
	{
		node* n=curr->next;
		curr->next=prev;
		prev=curr;
		curr=n;
	}
	return prev;
}

void bubbleSort(node* &head)
{
	int l=length(head);
	node* curr;
	node* prev;
	for(int i=0;i<l-1;i++)
	{
		curr=head;
		prev=NULL;

		while(curr && curr->next)
		{
			node* n=curr->next;
			if(curr->data>n->data)
			{
				if(prev==NULL)
				{
					curr->next=n->next;
					n->next=curr;
					prev=n;
					head=n;
				}
				else
				{
					curr->next=n->next;
					n->next=curr;
					prev->next=n;
					prev=n;
				}
			}
			else
			{
				prev=curr;
				curr=curr->next;
			}
		}
	}
}


void createCycle(node* head)
{
	node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}

	temp->next=head->next->next;
}

bool isCyclic(node* head)
{
	node* slow=head;
	node* fast=head;

	while(fast)
	{
		fast=fast->next;
		if(fast)
		{
			fast=fast->next;
			slow=slow->next;
			if(slow==fast)
			{
				return true;
			}
		}
	}
	return false;
}


void breakCycle(node* head)
{
	node* slow=head;
	node* fast=head;

	while(fast)
	{
		fast=fast->next->next;
		slow=slow->next;
		if(slow==fast)
		{
			break;
		}
	}

	node* prev=head;
	while(prev->next!=fast)
	{
		prev=prev->next;
	}

	slow=head;
	while(slow!=fast)
	{
		slow=slow->next;
		fast=fast->next;
		prev=prev->next;
	}

	prev->next=NULL;
}


void print(node* head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}





int main()
{
	// node* head=NULL;
	// node* tail=NULL;


	node* headA=NULL;
	node* tailA=NULL;
	node* headB=NULL;
	node* tailB=NULL;


	insertionAtFront(headA,tailA,7);
	insertionAtFront(headA,tailA,6);
	insertionAtFront(headA,tailA,5);
	insertionAtFront(headA,tailA,4);
	insertionAtFront(headA,tailA,3);
	insertionAtFront(headA,tailA,2);
	insertionAtFront(headA,tailA,1);

	// insertionAtFront(headA,tailA,34);
	// insertionAtFront(headA,tailA,20);
	// insertionAtFront(headA,tailA,11);
	// insertionAtFront(headA,tailA,100);
 //    insertionAtFront(headA,tailA,151);
	// insertionAtFront(headA,tailA,100);
	// insertionAtFront(headA,tailA,121);
	// insertionAtFront(headA,tailA,99);

	createCycle(headA);
	if(isCyclic(headA))
	{
		cout<<"isCyclic"<<endl;
		breakCycle(headA);
		print(headA);
		cout<<endl;
	}
	else
	{
		cout<<"Not Cyclic"<<endl;
	}

	// print(headA);
	// cout<<endl;



	// bubbleSort(headA);

	// print(headA);
	// cout<<endl;

	// node* nhead=reverseLL(headA);
	// print(nhead);
	// cout<<endl;

	// insertionAtFront(headB,tailB,23);
	// insertionAtFront(headB,tailB,19);
	// insertionAtFront(headB,tailB,10);

	// node* nhead=mergeSort(headA);

	// print(nhead);
	// cout<<endl;

	// print(headB);
	// cout<<endl;


	// node* nhead=merge(headA,headB);

	
	// print(nhead);
	// cout<<endl;

	// insertionAtFront(head,tail,3);
	// insertionAtFront(head,tail,2);
	// insertionAtFront(head,tail,1);
	// insertionAtEnd(head,tail,4);
	// insertionAtEnd(head,tail,5);
	// insertionAtEnd(head,tail,6);
	// insertionAtPos(head,tail,0,0);
	// insertionAtPos(head,tail,7,7);
	// insertionAtPos(head,tail,11,3);


	// print(head);
	// cout<<endl;

	// cout<<mid(head)->data<<endl;
	// cout<<length(head)<<endl;

	// deletionAtFront(head,tail);
	// deletionAtEnd(head,tail);

	// print(head);
	// cout<<endl;

	// deletionAtPos(head,tail,0);
	// deletionAtPos(head,tail,8);
	// deletionAtPos(head,tail,3);

	// print(head);
	// cout<<endl;

	// int d;
	// cin>>d;
	// node* n=search(head,d);
	// if(n)
	// {
	// 	cout<<n->data<<endl;
	// }
	// else
	// {
	// 	cout<<"Not found"<<endl;
	// }

	// n=searchRec(head,d);
	// if(n)
	// {
	// 	cout<<n->data<<endl;
	// }
	// else
	// {
	// 	cout<<"Not found"<<endl;
	// }
	return 0;
}
















