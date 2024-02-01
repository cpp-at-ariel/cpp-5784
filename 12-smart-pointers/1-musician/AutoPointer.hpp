/**
 * A demo implementation of an automatic pointer.
 * 
 * Author: Eran Kaufmann
 * Since:  2020-06
 */

template<typename T> class AutoPointer {
	T* ptr = nullptr;

public:
	AutoPointer()=default;

	// Convert from C pointer:
	AutoPointer(T* new_ptr):
		ptr(new_ptr) {}

	AutoPointer<T>& operator=(T* new_ptr) {
		if (ptr!=nullptr) delete ptr;
		ptr = new_ptr;
		return *this;
	}

	// Delete when out of scope:
	~AutoPointer() {
		if (ptr!=nullptr) delete ptr;
	}

	// Behave like C pointer:
	T* operator->(){
		return ptr;
	}

	T& operator*(){
		return *ptr;
	}

	// Do not allow to duplicate:
	AutoPointer(const AutoPointer& other) = delete;
	AutoPointer& operator=(const AutoPointer& other) = delete;
	AutoPointer(AutoPointer& other) = delete;
	AutoPointer& operator=(AutoPointer& other) = delete;
};
