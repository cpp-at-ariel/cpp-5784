#pragma once

#include <iostream>
#include <vector>
#include <cassert>

//---------------------------------------------------------------
template<typename T>
inline std::ostream& writePOD(std::ostream& out, const T& t) {
	out.write(reinterpret_cast<const char*>(&t),
			  sizeof(t));
	return out;
}
//---------------------------------------------------------------


//---------------------------------------------------------------
template<typename T>
inline std::ostream& writeVectorOfPOD(std::ostream& out, const std::vector<T>& t) {
	out.write(reinterpret_cast<const char*>(t.data()),
			  sizeof(T)*t.size());
	return out;
}
//---------------------------------------------------------------


//---------------------------------------------------------------
template<typename T>
inline std::istream& readPOD(std::istream& in, T& t) {
	in.read(reinterpret_cast<char*>(&t), sizeof(t));
	return in;
}
//---------------------------------------------------------------


//---------------------------------------------------------------
template<typename T>
inline std::istream& readVectorOfPOD(std::istream& in, std::vector<T>& vec) {
	in.read(reinterpret_cast<char*>(vec.data()), vec.size()*sizeof(T));
	return in;
}
//---------------------------------------------------------------




