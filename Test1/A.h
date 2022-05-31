#pragma once
#include<iostream>
using namespace std;
class A
{
public:
	int n;
	A* Next;
	A() {
		n = 5;
		Next = nullptr;
	}
	~A() {
		cout << "Îö¹¹A" << endl;
	}
};

