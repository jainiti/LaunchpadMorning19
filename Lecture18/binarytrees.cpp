#include<iostream>
#include<queue>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;

	node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};

node* createTree()
{

	int d;
	cin>>d;

	if(d==-1)
	{
		return NULL;
	}

	node* root=new node(d);
	cout<<"enter left child of "<<d<<" : ";
	root->left=createTree();
	cout<<"enter right child of "<<d<<" : ";
	root->right=createTree();

	return root;

}

void preOrder(node* root)
{
	if(root==NULL)
	{
		return;
	}

	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(node* root)
{
	if(root==NULL)
	{
		return;
	}

	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

void inOrder(node* root)
{
	if(root==NULL)
	{
		return;
	}

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

int height(node* root)
{
	if(root==NULL)
	{
		return 0;
	}

	int leftChildHeight=height(root->left);
	int rightChildHeight=height(root->right);

	int h=max(leftChildHeight,rightChildHeight)+1;
	return h;
}

int count(node* root)
{
	if(root==NULL)
	{
		return 0;
	}

	int leftCount=count(root->left);
	int rightCount=count(root->right);

	int totalCount=leftCount+rightCount+1;
	return totalCount;
}

int diameter(node* root)
{
	if(root==NULL)
	{
		return 0;
	}

	int op1=height(root->left)+height(root->right);
	int op2=diameter(root->left);
	int op3=diameter(root->right);

	int ans=max(op1,max(op2,op3));
	return ans;
}

class Pair
{
public:
	int Height;
	int Diameter;
};


Pair fastDiameter(node* root)
{
	Pair p;
	if(root==NULL)
	{
		p.Height=0;
		p.Diameter=0;
		return p;
	}

	Pair left=fastDiameter(root->left);
	Pair right=fastDiameter(root->right);

	p.Height=max(left.Height,right.Height)+1;

	int op1=left.Height+right.Height;
	int op2=left.Diameter;
	int op3=right.Diameter;

	p.Diameter=max(op1,max(op2,op3));

	return p;


}

void levelOrder(node* root)
{
	queue<node*>q;
	q.push(root);
	q.push(NULL);

	while(!q.empty())
	{
		node* n=q.front();
		q.pop();

		if(n==NULL)
		{
			cout<<endl;
			if(!q.empty())
			{
				q.push(NULL);
			}
		}
		else
		{
			cout<<n->data<<" ";
			if(n->left)
			{
				q.push(n->left);
			}

			if(n->right)
			{
				q.push(n->right);
			}
		}
	}
}


void mirror(node* root)
{
 	if(!root)
 	{
 		return;
 	}

 	swap(root->left,root->right);
 	mirror(root->left);
 	mirror(root->right);
}

int i=0;
int pre[]={1,2,4,8,5,9,3,6,7};

node* builtTree(int *in,int s,int e)
{
	if(s>e)
	{
		return NULL;
	}

	int key=pre[i];
	i++;
	int k=-1;
	for(int j=s;j<=e;j++)
	{
		if(in[j]==key)
		{
			k=j;
			break;
		}
	}

	node* root=new node(key);
	root->left=builtTree(in,s,k-1);
	root->right=builtTree(in,k+1,e);

	return root;


}


bool isBST(node* root,int min=INT_MIN,int max=INT_MAX)
{
	if(!root)
	{
		return true;
	}

	if((min<=root->data &&root->data<max)&&isBST(root->left,min,root->data)&&isBST(root->right,root->data+1,max))
	{
		return true;
	}

	return false;
}

node* insertInBST(node* root,int data)
{
	
	if(root==NULL)
	{
		node* r=new node(data);
		return r;
	}

	else if(root->data<data)
	{
		root->right=insertInBST(root->right,data);
	}

	else
	{
		root->left=insertInBST(root->left,data);
	}

	return root;
}


node* createBST()
{
	int data;
	cin>>data;

	node* root=NULL;
	while(data!=-1)
	{
		root=insertInBST(root,data);
		cin>>data;
	}
	return root;	
}


int main()
{
 
	// node *root=createTree();

	
	// int in[]={8,4,2,9,5,1,6,3,7};
	// int n=sizeof(in)/sizeof(int);

	// node* root=builtTree(in,0,n-1);
	// levelOrder(root);

	node* root=createBST();

	levelOrder(root);

	if(isBST(root))
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}

	// cout<<"preOrder traversal is  : ";
	// preOrder(root);
	// cout<<endl;
	// cout<<endl;


	// cout<<"postOrder traversal is : ";
	// postOrder(root);
	// cout<<endl;
	// cout<<endl;


	// cout<<"inOrder traversal is : ";
	// inOrder(root);
	// cout<<endl;
	// cout<<endl;

	// cout<<"height of tree is : ";
	// cout<<height(root);
	// cout<<endl;
	// cout<<endl;


	// cout<<"count of nodes are : ";
	// cout<<count(root);
	// cout<<endl;
	// cout<<endl;

	// Pair p=fastDiameter(root);
	// cout<<"height using fastDiameter is "<<p.Height<<endl;
	// cout<<"diameter using fastDiameter is "<<p.Diameter<<endl;

	// levelOrder(root);

	// mirror(root);

	// cout<<"mirror image "<<endl;
	// levelOrder(root);

	return 0;
}














