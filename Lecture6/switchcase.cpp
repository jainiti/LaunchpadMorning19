#include<iostream>
using namespace std;

int main()
{
	char ch;
	cin>>ch;

	switch(ch)
	{
		case 'm':
		case 'M': cout<<"monday"<<endl;
				  break;

		case 't':
		case 'T': cout<<"Tuesday"<<endl;
				  break;

		case 'w':
		case 'W': cout<<"wed"<<endl;
				  break;

		default: cout<<"any other day"<<endl;
	}
	return 0;
}

























