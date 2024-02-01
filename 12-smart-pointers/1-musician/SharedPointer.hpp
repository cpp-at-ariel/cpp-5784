/**
 * A demo implementation of a shared pointer.
 * 
 * Author: Eran Kaufmann
 * Since:  2020-06
 */

bool DEBUG=false;

template<typename T> class SharedPointer{

	struct ReferenceTracker {
		T* ptr=nullptr;
		int counter=0;
	};

	ReferenceTracker* tracker = nullptr;

public:
	SharedPointer()=default;

	SharedPointer(T* new_ptr): 
		tracker ( new ReferenceTracker {new_ptr, 1} )   { 
		if (DEBUG) std::cout << "In constructor: tracker = " << tracker << " tracker->counter = " << tracker->counter << std::endl;
	}

	// Copy constructor:
	SharedPointer(const SharedPointer<T>& other){
		tracker = other.tracker;
		tracker->counter++ ;
		if (DEBUG) std::cout << "In copy constructor: tracker = " << tracker << " tracker->counter = " << tracker->counter << std::endl;
	}

	// Delete when no remaining references:
	~SharedPointer(){
		if (!tracker) return;
		tracker->counter--;
		if (DEBUG) std::cout << "In destructor: tracker->counter = " << tracker->counter << std::endl;
		if (tracker->counter == 0) {
			delete tracker->ptr;
			delete tracker;
		}
	}

	// Assignment operator:
	SharedPointer& operator=(SharedPointer<T> const& other) {
		if (DEBUG)  {
			std::cout << "Start operator=: tracker = " << tracker;
			if (tracker) std::cout << " tracker->counter = " << tracker->counter;
			std::cout << std::endl;
		}
		if (tracker) {
			tracker->counter--;
			if (tracker->counter == 0) {
				delete tracker->ptr;
				// delete tracker;
			}
		}
		tracker = other.tracker;
		tracker->counter++ ;
		if (DEBUG) std::cout << "End operator=: tracker = " << tracker << " tracker->counter = " << tracker->counter << std::endl;
		return *this;
	}

	// // Move constructor:
	// SharedPointer(SharedPointer&& other){
	// 	*this=move(other);
	// }

	// // Move operator:
	// void operator=(SharedPointer&& other){
	// 	tracker->ptr = other.tracker->ptr;
	// }

	// Behave like C pointer:
	T* operator->(){
		return tracker->ptr;
	}
	T& operator*(){
		return *(tracker->ptr);
	}
};
