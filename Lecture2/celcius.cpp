#include<iostream>
using namespace std;

int main()
{
	int initial,step,final;
	cout<<"enter initial, step, final"<<endl;
	cin>>initial>>step>>final;

	int F=initial;
	while(F<=final)
	{
		int celcius=(5/9.0)*(F-32);
		cout<<F<<" "<<celcius<<endl;
		F=F+step;
	}
	return 0;
}