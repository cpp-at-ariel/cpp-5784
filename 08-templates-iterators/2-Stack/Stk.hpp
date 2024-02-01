/**
 * A template stack class.
 * Implemented as a linked list.
 * 
 * AUTHOR: Ofir Pele
 * SINCE : 2017
 */

#pragma once

template<typename T>
class Stk {

public:

	Stk() : m_first(nullptr) {
	}

	~Stk() {
		while (!isEmpty()) pop();
	}

	void push(const T& s) {
		m_first=new Node(s,m_first);
	}

	bool isEmpty() const {
		return m_first==nullptr;
	}

	// We return by const ref to avoid copying and because we want
	// to allow methods that gets Stk by const to see its top.
	const T& top() const {
		return m_first->m_value;
	}

	// Here we return by ref so it will allow a change of the object at the top.
	// Note that we can make it a const method: top() const {
	// and comment out the top() const method above
	// and it will compile but it will be a bad design as it will be a function
	// that can be activated on a const object and allow change of the "logical"
	// object. That is, the T objects that are inside the stack.
	T& top() {
		return m_first->m_value;
	}

	void pop() {
		Node* n= m_first;
		m_first= m_first->m_next;
		delete n;
	}
	
private:

	// Avoid copying
	Stk (const Stk& rhs);
	Stk& operator=(const Stk& rhs);

	// inner class
	struct Node {
		T m_value;
		Node* m_next;
		Node(const T& v, Node* n)
			: m_value(v), m_next(n) {
		}
	};

	// fields
	Node* m_first;
	
public:	

	//-------------------------------------------------------------------
	// iterator related code:
	// inner class and methods that return instances of it)
	//-------------------------------------------------------------------
	class iterator {

	  private:
		Node* pointer_to_current_node;

	public:

		iterator(Node* ptr = nullptr)
			: pointer_to_current_node(ptr) {
		}

		// Note that the method is const as this operator does not
		// allow changing of the iterator.
		// Note that it returns T& as it allows to change what it points to.
		// A const_iterator class will return const T&
		// and the method will still be const
		T& operator*() const {
			//return *pointer_to_current_node;
			return pointer_to_current_node->m_value;
		}

		T* operator->() const {
			return &(pointer_to_current_node->m_value);
		}

		// ++i;
		iterator& operator++() {
			//++pointer_to_current_node;
			pointer_to_current_node = pointer_to_current_node->m_next;
			return *this;
		}

		// i++;
		// Usually iterators are passed by value and not by const& as they are small.
		const iterator operator++(int) {
			iterator tmp= *this;
			pointer_to_current_node= pointer_to_current_node->m_next;
			return tmp;
		}

		bool operator==(const iterator& rhs) const {
			return pointer_to_current_node == rhs.pointer_to_current_node;
		}

		bool operator!=(const iterator& rhs) const {
			return pointer_to_current_node != rhs.pointer_to_current_node;
		}
	};  // END OF CLASS ITERATOR



	class const_iterator {

	  private:
		Node* pointer_to_current_node;

	public:

		const_iterator(Node* ptr = nullptr)
			: pointer_to_current_node(ptr) {
		}

		// Note that the method is const as this operator does not
		// allow changing of the iterator.
		// Note that it returns T& as it allows to change what it points to.
		// A const_iterator class will return const T&
		// and the method will still be const
		const T& operator*() const {
			//return *pointer_to_current_node;
			return pointer_to_current_node->m_value;
		}

		const T* operator->() const {
			return &(pointer_to_current_node->m_value);
		}

		// ++i;
		const_iterator& operator++() {
			//++pointer_to_current_node;
			pointer_to_current_node = pointer_to_current_node->m_next;
			return *this;
		}

		// i++;
		// Usually iterators are passed by value and not by const& as they are small.
		const const_iterator operator++(int) {
			const_iterator tmp= *this;
			pointer_to_current_node= pointer_to_current_node->m_next;
			return tmp;
		}

		bool operator==(const const_iterator& rhs) const {
			return pointer_to_current_node == rhs.pointer_to_current_node;
		}

		bool operator!=(const const_iterator& rhs) const {
			return pointer_to_current_node != rhs.pointer_to_current_node;
		}
	};  // END OF CLASS const_iterator



	iterator begin() {
		// return &(m_first->m_value); 
		return iterator{m_first};
	}
	
	iterator end() {
		// return nullptr; 
		return iterator{nullptr};
	}

	const_iterator cbegin() const {
		return const_iterator{m_first};
	}
	
	const_iterator cend() const {
		return const_iterator{nullptr};
	}

	//-------------------------------------------------------------------

/*
	class reverse_iterator {
		...
	};

	reverse_iterator rbegin() {

	};

	reverse_iterator rend() {

	};
*/


	//-------------------------------------------------------------------
	// generic constructor:
	// template constructor inside a template class!
	//-------------------------------------------------------------------
	template<typename IT>
	Stk(IT begin, IT end): Stk() {
		for (; begin!=end; ++begin) {
			push(*begin);
		}
	}
	//-------------------------------------------------------------------
	
}; 
