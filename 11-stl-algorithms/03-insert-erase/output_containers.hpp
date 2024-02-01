#pragma once
#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <deque>
using namespace std;


template<typename T>
ostream& operator<< (ostream& out, const vector<T>& c) {
	for (int i: c)
		out << i << ' ';
	return out;
}
template<typename T>
ostream& operator<< (ostream& out, const set<T>& c) {
	for (int i: c)
		out << i << ' ';
	return out;
}

template<typename T>
ostream& operator<< (ostream& out, const list<T>& c) {
	for (int i: c)
		out << i << ' ';
	return out;
}

template<typename T>
ostream& operator<< (ostream& out, const deque<T>& c) {
	for (int i: c)
		out << i << ' ';
	return out;
}
