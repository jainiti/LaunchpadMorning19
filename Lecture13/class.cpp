#include<iostream>
using namespace std;

// int count;

class car
{
	int tyres;
public:
	char *name;
	int seats;
	int price;
	static int count;
	
	char color[100];


	car():name(NULL)
	{
		count++;
		cout<<"default constructor"<<endl;
		// name=NULL;
	}

	car(char *n,int s,int p,int t,char *col):seats(4),price(p)
	{
		count++;
		cout<<"parametrised constructor"<<endl;
		name= new char[strlen(n)+1];
        strcpy(name,n);
		// seats=s;
		// price=p;
		// tyres=t;
		strcpy(color,col);
	}

	void print()
	{
		cout<<"name : "<<name<<endl;
		cout<<"seats : "<<seats<<endl;
		cout<<"price : "<<price<<endl;
		cout<<"tyres : "<<tyres<<endl;
		cout<<"color : "<<color<<endl;
		cout<<endl;
	}

	car(car &X)
	{
		count++;
		cout<<"Copy constructor"<<endl;
		name=new char[strlen(X.name)+1];
		strcpy(name,X.name);
		seats=X.seats;
		price=X.price;
		tyres=X.tyres;
		strcpy(color,X.color);
	}

	void operator=(car X)
	{
		name=new char[strlen(X.name)+1];
		strcpy(name,X.name);
		seats=X.seats;
		price=X.price;
		tyres=X.tyres;
		strcpy(color,X.color); 

	}


	void operator+=(car X)
	{
		char *oldname=name;
		name=new char[strlen(name)+strlen(X.name)+1];
		strcpy(name,oldname);
		strcat(name,X.name);
		delete []oldname;

		tyres+=X.tyres;
		price+=X.price;
		seats+=X.seats;
		strcpy(color,X.color);
	}

	// car* operator+(car X)
	// {
	// 	car G;
	// 	G.name=new char[strlen(name)+strlen(X.name)+1];
	// 	strcpy(G.name,name);
	// 	strcat(G.name,X.name);
	// }



	void setName(char *n)
	{
		if(name!=NULL)
		{
			delete []name;
			name=NULL;
		}
		name=new char[strlen(n)+1];
		strcpy(name,n);
	}

	void setTyre(int t)
	{
		if(tyres>=0)
		{
			tyres=t;
		}
		else
		{
			tyres=4;
		}

		
	}

	~car()
	{
		count--;
		cout<<"Deleting car : "<<name<<endl;
	}



};

int car::count=0;


int main()
{
	car A;
	car B("Audi",4,20000,4,"yellow");
	A.name=new char[10];
	A.setName("BMW");
	// strcpy(A.name,"BMW");
	A.seats=4;
	A.price=10000;
	// A.tyres=4;
	A.setTyre(0);
	strcpy(A.color,"black");

	
	// cout<<"name : "<<A.name<<endl;
	// cout<<"seats : "<<A.seats<<endl;
	// cout<<"price : "<<A.price<<endl;
	// cout<<"tyres : "<<A.tyres<<endl;
	// cout<<"color : "<<A.color<<endl;

	B.setName("ALTO");
	

	car C(A);
	C.name[0]='W';
	car D=A;



	// int count;
	// count++;
	car E;
	E=D;

	E+=B;

	car *G=new car;     //OR car *G=new car()
	G->name="ABC";

	A.print();
	B.print();
	C.print();
	D.print();
	E.print();

	cout<<car::count<<endl;
	delete G;
	cout<<car::count<<endl;
	return 0;
}








