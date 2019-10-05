#include<iostream>
using namespace std;

class car
{
public:
	char *name;
	int seats;
	int price;
	int tyres;
	char color[100];


	car()
	{
		cout<<"default constructor"<<endl;
		name=NULL;
	}

	car(char *n,int s,int p,int t,char *col)
	{

		cout<<"parametrised constructor"<<endl;
		name= new char[strlen(n)+1];
        strcpy(name,n);
		seats=s;
		price=p;
		tyres=t;
		strcpy(color,col);
	}

	void print()
	{
		cout<<"name : "<<name<<endl;
		cout<<"seats : "<<seats<<endl;
		cout<<"price : "<<price<<endl;
		cout<<"tyres : "<<tyres<<endl;
		cout<<"color : "<<color<<endl;
	}

};


int main()
{
	car A;
	car B("Audi",4,20000,4,"yellow");
	A.name=new char[10];
	strcpy(A.name,"BMW");
	A.seats=4;
	A.price=10000;
	A.tyres=4;
	strcpy(A.color,"black");


	cout<<"name : "<<A.name<<endl;
	cout<<"seats : "<<A.seats<<endl;
	cout<<"price : "<<A.price<<endl;
	cout<<"tyres : "<<A.tyres<<endl;
	cout<<"color : "<<A.color<<endl;

	B.print();
	return 0;
}








