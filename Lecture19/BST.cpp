#include <iostream>
#include <queue>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int d):data(d),left(NULL),right(NULL){}
};

node* LevelOrderBST(){
	node* root=NULL;

	cout<<"Enter data for root Node ";
	int data;
	cin>>data;
	if(data == -1){
		return root;
	}
	queue<node*> q;
	root = new node(data);// Created the root node
	q.push(root);

	while(!q.empty()){
		node* temp = q.front();
		q.pop();

		cout<<"Enter the children of "<<temp->data<<" ";
		int c1,c2;
		cin>>c1>>c2;
		if(c1!=-1){
			// Child exists
			temp->left = new node(c1);
			q.push(temp->left);
		}
		if(c2!=-1){
			temp->right = new node(c2);
			q.push(temp->right);
		}
	}

	return root;
}

void levelOrderPrint(node* root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* temp = q.front();
		q.pop();

		if(temp == NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<temp->data<<" ";
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}
}

node* deleteBST(node* root,int key){
	if(root == NULL){
		return NULL;
	}
	else if(root->data>key){
		root->left = deleteBST(root->left,key);
		return root;
	}
	else if(root->data<key){
		root->right = deleteBST(root->right,key);
		return root;
	}
	else{
		// Cases
		//1 . 0 child
		if(root->left == NULL && root->right == NULL){
			delete root;
			return NULL;
		}
		//2 . 1 child
		else if(root->left!=NULL && root->right == NULL){
			node* temp = root->left;
			delete root;
			return temp;
		}
		else if(root->left==NULL && root->right != NULL){
			node* temp = root->right;
			delete root;
			return temp;
		}
		else{
			//3 . 2 child	
			node* temp = root->right;
			while(temp->left!=NULL){
				temp=temp->left;
			}
			root->data = temp->data;
			root->right = deleteBST(root->right,root->data);
			return root;
		}
		
		
	}

}

class linkedlist{
public:
	node* head;
	node* tail;
};

linkedlist BSTtoLL(node* root){
	linkedlist l;
	if(root == NULL){
		l.head = l.tail =NULL;
		return l;
	}
	else if(root->left == NULL && root->right == NULL){
		l.head = l.tail = root;
		return l;
	}
	else if(root->left != NULL && root->right == NULL){
		linkedlist left = BSTtoLL(root->left);
		left.tail->right = root;
		l.head = left.head;
		l.tail = root;
		return l;
	}
	else if(root->left == NULL && root->right != NULL){
		linkedlist right = BSTtoLL(root->right);
		root->right = right.head;
		l.head = root;
		l.tail = right.tail;
		return l; // 147202
	}
	else{
		linkedlist left = BSTtoLL(root->left);
		linkedlist right = BSTtoLL(root->right);
		left.tail->right = root;
		root->right = right.head;
		l.head = left.head;
		l.tail = right.tail;
		return l;
	}
}

void PrintLL(node* head){
	while(head){
		cout<<head->data<<"-->";
		head = head->right;
	}
	cout<<endl;
}

node* InsertInBST(node* root,int data){
	if(root == NULL){
		root = new node(data);
		return root;
	}
	if(root->data<data){
		root->right = InsertInBST(root->right,data);
	}
	else{
		root->left = InsertInBST(root->left,data);
	}
	return root;
}

node* buildTree(){
	node* root = NULL;
	int data;
	cin>>data;

	while(data!=-1){
		root = InsertInBST(root,data);
		cin>>data;
	}
	return root;
}

void inorder(node* root){
	if(root == NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}



int main(){
	node* root = buildTree();
	levelOrderPrint(root);
	linkedlist l = BSTtoLL(root);
	PrintLL(l.head);

	return 0;
}