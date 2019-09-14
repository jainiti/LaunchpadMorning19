#include<iostream>
using namespace std;

void celciusconverter(int start,int step,int final)
{
	for(int f=start;f<=final;f=f+step)
	{
		int celcius=(5/9.0)*(f-32);
		cout<<f<<" "<<celcius<<endl;
	}
	return;
}

int main()
{
	int start,step,final;
	cin>>start>>step>>final;

	celciusconverter(start,step,final);
	return 0;
}