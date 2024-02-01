/**
 * A template buffer with:
 *  * iterator,
 *  * const_iterator.
 * 
 * AUTHOR: Ofir Pele, 2017.
 * 
 * Modified by: Erel Segal-Halevi, 2018.
 */

#include <cassert>
#include <cstdlib> // for size_t

template<typename T>
void myswap(T& a, T& b) {
	T tmp= a;
	a= b;
	b= tmp;
}

template<typename T>
class Buffer {

private:
	T* _buf;
	size_t _size;

	//---------------------------------------------------------
	// private helpers
	//---------------------------------------------------------
	void copyVals(const Buffer& other) {
		for (size_t i= 0; i<other.size(); ++i) {
			(*this)[i]= other[i];
		}
	}

	void freeMemory() {
		delete[] _buf;
	}
	
	static T* getMemory(size_t size) {
		return new T[size];
	}
	//---------------------------------------------------------
	
public:

	size_t size() const {
		return _size;
	}
	
	explicit Buffer(size_t size) : _buf(getMemory(size)), _size(size) {}
	
	//---------------------------------------------------------
	// Rule of three (in C++11 it will be rule of 5)
	//---------------------------------------------------------
	Buffer(const Buffer& other) :
		_buf(getMemory(other.size())),
		_size(other.size())	{
		
		copyVals(other);

	}

	~Buffer() {
		freeMemory();
	}

	Buffer& operator=(const Buffer& other) {
		if (this!=&other) {
			freeMemory(); // why not, call destructor or delete this?
			              // answer: undefined behavior as we use destructor twice.
			              // Destructor is not only its body!
			_buf= getMemory(other.size());
			_size= other.size();
			copyVals(other);
		}
		return *this;
	}
	//---------------------------------------------------------

	//---------------------------------------------------------
	// Accessors
	//---------------------------------------------------------
	T& operator[](size_t i) {
		assert(i<size());
		return _buf[i];
	}

	const T& operator[](size_t i) const {
		assert(i<size());
		return _buf[i];
	}
	//---------------------------------------------------------

	//---------------------------------------------------------
	// Iterators related (not safe - for safe we need inner classes instead of typedefs)
	//---------------------------------------------------------
	using iterator = T*;    // here using=typedef
	using const_iterator = const T*;

	iterator begin() {
		return _buf;
	}
	iterator end() {
		return _buf+_size;
	}

	const_iterator begin() const {
		return _buf;
	}
	const_iterator end() const {
		return _buf+_size;
	}	//---------------------------------------------------------



	//---------------------------------------------------------
	// efficiently swapping 
	//---------------------------------------------------------
	void myswap(Buffer& other) {
		::myswap(_buf, other._buf);
		::myswap(_size, other._size);
	}
	
};

#include <iostream>

template<typename T>
void myswap(Buffer<T>& b1, Buffer<T>& b2) {
	std::cout << "Special swap" << std::endl;
	b1.myswap(b2);
}
//---------------------------------------------------------


