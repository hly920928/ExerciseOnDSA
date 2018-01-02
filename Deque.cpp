#include "stdafx.h"
#include <list>
using  namespace std;
template<typename T>
class Deque {
private:
	list<T> data;
public:
	Deque() {};
	int size() { return data.size();}
	T front() { return *(data.begin()); }
	T back() { return *(--data.end()); }
	void push_front(T a) { 
		data.insert(data.begin(), a);
	}
	T pop_front() { 
		T t = *(data.begin()); 
		data.erase(data.begin());
		return t; }
	void push_back(T a) { 
		data.insert(data.end(), a); 
	}
	T pop_back() {
		auto itr = --data.end();
		T t = *itr;
		data.erase(itr);
		return t; }
	void trav(void(*f)(T& a)) {
		for (auto& t : data) f(t);
	}
	void trav(void(*f)(T a)) {
		for (auto& t : data) f(t);
	}
};
