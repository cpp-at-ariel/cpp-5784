/**
 * We wrote a stack using pointers.
 * Here is the same stack using smart pointers.
 * 
 * Author: Eran Kaufmann
 * Since : 2020-06
 */

#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>
using namespace std;





struct Stack{

	struct Node{
		int data=8;
		shared_ptr<Node> next;
	};

	shared_ptr<Node> head;

	void push(int data){
		auto temp = make_shared<Node>();
		temp->data=data;
		temp->next = head;
		head = temp;
	}

	void pop() {
		head = head->next;
	}

	struct iterator{
		shared_ptr<Node> curr;
		iterator(shared_ptr<Node> a):curr(a){};
		void operator++(){
			curr = curr->next;
		}
		bool operator!=(iterator& o){
			return curr != o.curr;
		}
		int& operator*(){
			return curr->data;
		}
	};

	iterator begin(){
		return head;
	}

	iterator end(){
		return iterator(nullptr);
	}

};


int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    for(auto& i : s)
    	cout << i << " ";
    cout << endl;

}
