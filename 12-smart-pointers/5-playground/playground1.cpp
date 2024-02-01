#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>
using namespace std;

int main(){
	unique_ptr<string> ptr;//(new std::string("hello"));
	unique_ptr<string> ptr2 (new std::string("hello"));
	ptr = move(ptr2);
	vector<unique_ptr<string>> v;
	v.push_back(move(ptr));

	shared_ptr<string> p(new std::string("hello"));

	vector<shared_ptr<string>> vs;
	{
		shared_ptr<string> p2;
		p2=p;

	}
	vs.push_back(p);
	p=nullptr;
	vs.clear();

	auto sp = make_shared<string>("hi");
}
