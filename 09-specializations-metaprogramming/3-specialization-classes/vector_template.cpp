/**
 * Specialization of a vector class to handle vector<bool> more efficiently.
 * 
 * @author  Peter Gottschling
 * @url     https://github.com/petergottschling/discovering_modern_cpp/blob/master/c%2B%2B11/derivative.cpp
 */

#include <cassert>
#include <iostream>
#include <memory>
#include <algorithm>


/*
 * PART A: Generic vector class
 */

template <typename T>
class vector {
    int my_size;
    T*  data;
    void check_index(int i) const { assert(i >= 0 && i < my_size); }

  public:
    explicit vector(int size): 
      my_size(size), data( new T[my_size] )  {}

    vector(): my_size(0), data(nullptr) {}
    ~vector() {delete[] data;}

    int size() const { return my_size; }

    const T& operator[](int i) const {
        check_index(i);
        return data[i];
    }

    T& operator[](int i) {
        check_index(i);
        return data[i];
    }
};


template <typename T>
std::ostream& operator<<(std::ostream& os, const vector<T>& v) {
  os << '[';
  for (int i= 0; i < v.size(); ++i) 
    os << v[i] << ',';
  os << ']';
  return os;
}




/*
 * PART B: Specialization of vector to bool
 */


/**
 * A proxy to a bit - represents a reference to a single bit inside a char.
 */
class bool_reference {
  private:
    uint8_t& byte;
    uint8_t  mask;
    
  public:
    bool_reference(uint8_t& containing_byte, int bit_index): 
      byte(containing_byte), 
      mask(1 << bit_index) {}

    operator bool() const { 
      return ((byte & mask) == 0? false: true); 
      // EXAMPLE: byte = 0b10101?10
      // bit_index = 2
      // mask          = 0b00000100
      // byte & mask   = 0b00000?00
      // (bit=false: byte&mask == 0)
      // (bit=true: byte&mask  != 0)
    }

    bool_reference& operator=(bool b) { 
        if (b==true)
            byte |= mask;
        else // b==false
            byte &= ~mask;
        return *this;
    }

};

template <>
class vector<bool> {
    int      my_size;
    uint8_t* data;
    void check_index(int i) const { assert(i >= 0 && i < my_size); }
  public:
    explicit vector(int size):
      my_size(size),
      data(new uint8_t[(my_size+7) / 8]) {}

    vector(): my_size(0), data(nullptr) {}
  
    bool operator[](int i) const {
      check_index(i);
      return (data[i/8] >> i%8) & 1;
    }
    // EXAMPLE:
    // i = 10
    // i/8 = 1
    // i%8 = 2
    //
    // 10101010 10000?00
    // 10000?00
    //
    // >> 2:
    //   10000?
    //
    //   & 1:
    // 00000001
    //
    //   00000?

    // Does not work (1):
    // bool& operator[](int i) { 
    //   check_index(i);
    //   return (bool)((data[i/8] >> i%8) & 1);
    // }

    // Does not work (2): 
    // bool& operator[](int i) { 
    //   check_index(i);
    //   bool b = (data[i/8] >> i%8) & 1;
    //   return b;
    //   //return data[i/8];
    // }

    void set(int i, bool b) { 
      check_index(i);
      uint8_t mask = (0b00000001 << (i%8));
      // EXAMPLE: i = 10, i%8 == 2,
      // 1 << 2  == 0b00000100 = 4
      if (b) {
        data[i/8] = data[i/8] | mask;
      } else {
        data[i/8] = data[i/8] & (~mask);
      }
    }

    // Does not work (3): 
    // bool& operator[](int i, bool b) { 
    //   set(i,b);
    // }



    bool_reference operator[](int i) { 
      check_index(i);
      return bool_reference{data[i/8], i%8};   
    }

    int size() const { return my_size; }
    // NOTE: size() is not "inherited" from the generic vector!
    // You must define it, with all other methods,
    // in each specialization!
};

int main() {
    vector<float> v( 4 );
    v[0]= v[1]= 1.0; v[2]= 2.0; v[3] = -3.0;
    std::cout << "v = " << v << std::endl;

    vector<bool>  b(13);
    b[10] = true;  // equivalent to:
    // bool_reference br = b.operator[](10)
    // br.operator=(true);
    bool b10 = b[10]; // equivalent to:
    // bool_reference br = b.operator[](10)
    // b10 = br.operator bool();

    std::cout << std::boolalpha;
    for (int i= 0; i < 13; i++)
		  b[i] = i % 3;
    std::cout << "b = " << b << std::endl;

    return 0;
}
