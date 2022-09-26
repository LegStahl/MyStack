#ifndef STACK
#define STACK
#include <iostream>
template <typename T>
class Stack {
	//template<typename T> friend std::ostream& operator<<(std::ostream& os, const Stack<T>& foo);
private:
	struct list {
	T value;
	list* pointer;
	};
	list* root;
	int count;
	template<typename T> friend std::ostream& operator<<(std::ostream& os, Stack<T>& foo);
public:
	Stack();
	~Stack();
	bool StPush(T value);
	T StPop();
	int StSize();
};

template <typename T>
Stack<typename T>::Stack() {
	root = nullptr;
	count = 0; 
}

template <typename T>
Stack<typename T>::~Stack() {
	list* ptr = root;
	for (;root != nullptr;) {
		root = root->pointer;
		delete ptr;
		ptr = root;
	}
}
template <typename T>
bool Stack<typename T>::StPush(T value1) {
	if (count == 0) {
		root = new list;
		root->value = value1;
		root->pointer = nullptr;
		count++;
		return true;
	}
	else {
		list* ptr = new list;
		ptr->value = value1;
		ptr->pointer = root;
		root = ptr;
		count++;
		return true;
	}
}

template <typename T>
T Stack<typename T>::StPop() {
	if (count != 0) {
		list* ptr = root->pointer;
		T value2 = root->value;
		delete root;
		root = ptr;
		count--;
		return value2;
	}
}

template<typename T>
int Stack<typename T>::StSize() {
	return count;
}

template <typename T>
std::ostream& operator<<(std::ostream& out,  Stack<T>& rhs) {
	Stack<T> r;
	r.root = rhs.root;
	for (;r.root != nullptr;) {
		std::cout << r.root->value << " ";
		r.root =r.root->pointer;
	}
	return out;
}
#endif
