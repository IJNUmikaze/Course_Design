#pragma once
#include<string>
using namespace std;
class Computer
{
public:
	void SetAmount(int x);
	void SetFlag(int flag);
	void SetComponent(string str);
	void SetPrice(double x);
	void SetType(string str);
	void SetClass(string str);
	void SetManufacturer(string str);
	void SetTime(string str);
	void SetUseful(bool Flag);
	int GetAmount();
	bool GetFlag();
	string GetComponent();
	double GetPrice();
	string GetType();
	string GetClass();
	string GetManufacturer();
	string GetTime();
	bool GetUseful();
    Computer();
	~Computer(){}
private:
	string Component;
	double Price;
	string Type;
	string Class;
	string Manufacturer;
	string Time;
	bool Useful;
	static int Amount;
	static bool Flag;
};

