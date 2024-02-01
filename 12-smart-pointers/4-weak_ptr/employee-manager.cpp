/**
 * Demonstrates the need for weak_ptr.
 * 
 * Author: Eran Kaufmann.
 * Since: 2020.
 */

#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>
using namespace std;


struct Employee;

struct Manager{
	vector<shared_ptr<Employee>> employees;
	// vector<weak_ptr<Employee>> employees;
	void ask_for_vacation() {}
	~Manager() {
//		for(auto& emp:employees)
//			emp->manager=nullptr;
		{cout << "Manager I'm done \n";};
	}
};

struct Employee{

	int id;
	string name;
	weak_ptr<Manager> manager;
	// shared_ptr<Manager> manager;

	void take_vacation(){
		if(auto p = manager.lock())
		if(!manager.expired()){
			auto p = manager.lock();
			p -> ask_for_vacation();
		}
	}

	~Employee(){cout << "Employee I'm done \n";};

};



int main(){
	auto bob  = make_shared<Manager>();
	auto kate = make_shared<Employee>();
	bob->employees.push_back(kate);
	kate->manager=bob;
}
