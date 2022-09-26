#include<iostream>
#include"Stack.h"

int main() {
	Stack<int> f;
	f.StPush(24);
	f.StPush(4);
	f.StPush(43);
	f.StPush(0);
	std::cout << f << std::endl;
	f.StPop();
	f.StPop();
	std::cout << f;
	f.StPop();
	f.StPop();
	f.StPop();
	return 0;
}