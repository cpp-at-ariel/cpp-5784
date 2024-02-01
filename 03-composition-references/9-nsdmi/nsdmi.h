#pragma once

//
//struct A {
//	int p;
//	A(int _p):p(_p){};
//
//};
//
//struct B {
//
//	A a{5};
//	B(){};
//
//	B(int t){
//		a=t;
//	}
//
//};


//Non - static Data Member Initializers

template <typename T>
class stack
{
private:
	static const int DEFAULT_SIZE = 100;
	T* elements_ = new T[DEFAULT_SIZE];
	size_t top_ = 0;
	size_t size_ = DEFAULT_SIZE;

public:
	stack()
	{
	}

	stack(size_t size) : elements_(new T[size]), size_(size)
	{
	}

//	How ever this one causes memory leakage.
/*
	stack(size_t size)  //
	{
		size_ = size;
		elements_ = new T[size];
	}
*/

	~stack() {
		delete[] elements_;
	}


	bool empty() const
	{
		return top_ == 0;
	}

	bool full() const
	{
		return top_ == size_ - 1;
	}

	bool push(T const& t)
	{
		if (full())
		{
			return false;
		}
		elements_[top_++] = t;
		return true;
	}

	bool pop(T& t)
	{
		if (empty())
		{
			return false;
		}
		t = elements_[--top_];
		return true;
	}
};

void use_stack()
{
	stack<int> stack_;

	stack_.push(5);

}
