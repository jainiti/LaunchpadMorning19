#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int row=1;
	while(row<=n)
	{
		int space=1;
		while(space<=n-row)
		{
			cout<<" ";
			space=space+1;
		}
		int no=1;
		while(no<=2*row-1)
		{
			cout<<no;
			no=no+1;
		}
		cout<<endl;
		row=row+1;
	}
	return 0;
}













