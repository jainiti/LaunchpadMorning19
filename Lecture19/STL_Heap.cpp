#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MeraComparator{
public:
	bool operator()(int a,int b){
		cout<<a<<" "<<b<<endl;
		return a<b;
	}
};

int main(){

	priority_queue<int,vector<int>,MeraComparator> h;

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