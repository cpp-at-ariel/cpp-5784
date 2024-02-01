#include <iostream>
using namespace std;


//multiple inheritance and virtual inheritance
class List{
public:
	List(){};//add();};
	~List(){};//add();};
	int m_a;
    virtual void add(){ // should this be a virtual function ??
		cout << "List::add"<< endl;
	}

	virtual void addAll(object[]){
			cout << "Base:addAll"<< endl;
				for (///)
						add();
	}
	
	virtual char* my_name(){
		return "Base";
	}

	void print(){
		cout << my_name();
	}
};


class CarList : public List{
int count;
public:
int m_a;

     CarList(){};//add();};
	~CarList(){};//add();};
    void add(){
		count++;
		cout << "derived:add"<< endl;
		List::add();
	}
//
	void addAll(){
		count++;

		cout << "derived:addAll"<< endl;
		//add();
		List::addAll();
	}

	virtual char* my_name(){
		 return "Derived";
	 }

};

class vehicle{
protected:
	int name;

public:
	vehicle(){name=1;cout <<"vechile" << endl; };
	void takeAride(){};
};

class Taxi:public  vehicle{
public:

	Taxi(){name=2;cout <<"Taxi" << endl; };

	void takeApessenger(){};
};

class Scooter:public  vehicle{
public:

	Scooter(){cout <<"Scooter" << endl; };

	void deliver(){};
};

class yellowTaxi:public Taxi,Scooter{
public:
	yellowTaxi(){cout <<"yellowTaxi" << endl; };

	void drive(){takeAride();};
};

class Shape{
	virtual void draw()=0;//pure virtual
};

class square : Shape{
	virtual void draw(){ cout << 'h'};
};


class circle : Shape{
	virtual void draw(){ cout << 'c'};
};



int main(){
	CarList l;
	l.addall();
    yellowTaxi taxi;
}
