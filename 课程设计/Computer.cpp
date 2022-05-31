#include "Computer.h"
int Computer::Amount = 0;
bool Computer::Flag = false;
Computer::Computer() {
	Component = "No Data";
	Price = 0;
	Type = "No Data";
	Class = "No Data";
	Manufacturer = "No Data";
	Time = "No Data";
	Useful = false;
}
void Computer::SetAmount(int x) {
	Amount = x;
	return;
}
void Computer::SetFlag(int flag) {
	Flag = flag;
	return;
}
void Computer::SetComponent(string str) {
	Component = str;
	return;
}
void Computer::SetPrice(double x) {
	Price = x;
	return;
}
void Computer::SetType(string str) {
	Type = str;
	return;
}
void Computer::SetClass(string str) {
	Class = str;
	return;
}
void Computer::SetManufacturer(string str) {
	Manufacturer = str;
	return;
}
void Computer::SetTime(string str) {
	Time = str;
	return;
}
void Computer::SetUseful(bool Flag) {
	Useful = Flag;
	return;
}
int Computer::GetAmount() {
	return Amount;
}
bool Computer::GetFlag() {
	return Flag;
}
string Computer::GetComponent() {
	return Component;
}
double Computer::GetPrice() {
	return Price;
}
string Computer::GetType() {
	return Type;
}
string Computer::GetClass() {
	return Class;
}
string Computer::GetManufacturer() {
	return Manufacturer;
}
string Computer::GetTime() {
	return Time;
}
bool Computer::GetUseful() {
	return Useful;
}