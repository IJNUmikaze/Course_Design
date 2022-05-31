#include<iostream>
#include"A.h"
using namespace std;
A* fx(int x) {
	A fuck;
	A* p = new A;
	delete p;
	return p;
}
int main() {
	int a = 5;
	A* p = nullptr;
	p=fx(a);
	return 0;
}