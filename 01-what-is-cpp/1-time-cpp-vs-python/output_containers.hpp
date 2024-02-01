#pragma once
#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <list>
#include <deque>
#include <map>
using namespace std;

template<typename IT> string tostring(IT begin, IT end) {
	ostringstream ostr;
	for (; begin!=end; ++begin)
		ostr << (*begin) << " ";
	return ostr.str();
}

template<typename T>
ostream& operator<< (ostream& out, const vector<T>& c) {
	return out << tostring(begin(c), end(c));
}


template<typename T, unsigned long N>
ostream& operator<< (ostream& out, const array<T,N>& c) {
	return out << tostring(begin(c), end(c));
}

template<typename T>
ostream& operator<< (ostream& out, const set<T>& c) {
	return out << tostring(begin(c), end(c));
}

template<typename T>
ostream& operator<< (ostream& out, const list<T>& c) {
	return out << tostring(begin(c), end(c));
}

template<typename T>
ostream& operator<< (ostream& out, const deque<T>& c) {
	return out << tostring(begin(c), end(c));
}

template<typename K, typename V>
ostream& operator<< (ostream& out, const map<K,V>& c) {
	for (auto kv: c)
		out << kv.first << ":" << kv.second << ' ';
	return out;
}

template<typename K, typename V>
ostream& operator<< (ostream& out, const map<set<K>,V>& c) {
	for (auto kv: c)
		out << "{" << kv.first << "}: " << kv.second << endl;
	return out;
}
