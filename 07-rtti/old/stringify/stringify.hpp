/// Contains stringify functions that convert all types that can be printed to
/// std::ostream to std::string.
/// Contains template specialization for formatting.
/// Remark: c++11 has to_string functions for primitives.
#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cassert>

//------------------------------------------
// stringify_format for all kind of types
//------------------------------------------
template<typename T>
inline void stringify_format(std::ostringstream& out) {
}

template<>
inline void stringify_format<bool>(std::ostringstream& out) {
    out << std::boolalpha;
}


template<>
inline void stringify_format<float>(std::ostringstream& out) {
    const int sigdigits = std::numeric_limits<float>::digits10;
    out << std::setprecision(sigdigits);
}

template<>
inline void stringify_format<double>(std::ostringstream& out) {
    const int sigdigits = std::numeric_limits<double>::digits10;
    out << std::setprecision(sigdigits);
}

template<>
inline void stringify_format<long double>(std::ostringstream& out) {
    const int sigdigits = std::numeric_limits<long double>::digits10;
    out << std::setprecision(sigdigits);
}
//------------------------------------------




///------------------------------------------
/// converts to std::string the given param 
///------------------------------------------
template<typename T>
inline std::string stringify(const T& x) {
    std::ostringstream out;
    stringify_format<T>(out);
	out<<x;
	assert(out);
    return out.str();
}
//------------------------------------------
