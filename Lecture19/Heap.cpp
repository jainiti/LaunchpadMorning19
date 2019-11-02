#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Minheap{
	vector<int> v;

	void heapify(int index){
		int left = 2*index;
		int right = left +1;
		int min_index = index;

		if(left<v.size() && v[min_index]>v[left]){
			min_index = left;
		}
		if(right<v.size() && v[min_index]>v[right]){
			min_index = right;
		}

		if(min_index!=index){
			swap(v[index],v[min_index]);
			heapify(min_index);
		}
	}


public:
	Minheap(){
		v.push_back(-1);
	}

	void push(int data){
		v.push_back(data);
		int children  = v.size() - 1;
		int parent = children/2;
		while(parent>0 && v[parent]>v[children]){
			swap(v[parent],v[children]);
			children = parent;
			parent = parent/2;
		}
	}

	int top(){
		return v[1];
	}

	bool empty(){
		return v.size() == 1;
	}

	void pop(){
		swap(v[1],v[v.size()-1]);
		v.pop_back();

		heapify(1);
	}
	

};


int main(){

	Minheap h;

	h.push(10);
	h.push(2);
	h.push(-3);
	h.push(4);
	h.push(11);
	h.push(15);

	while(!h.empty()){
		cout<<h.top()<<endl;
		h.pop();
	}








	return 0;
}