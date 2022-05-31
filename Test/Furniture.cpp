#include "Furniture.h"
#include<sstream>
using namespace std;
Furniture::Furniture(string articleNum, string productName, int stockAmount) {
	this->articleNum = articleNum;
	productName = productName;
	this->stockAmount = stockAmount;
}
void Furniture::setArticleNum(string articleNum) {
	this->articleNum = articleNum;
}
string Furniture::getArticleNum()const {
	return this->articleNum;
}

void Furniture::setProductName(string productName) {
	this->productName = productName;
}
string Furniture::getProductName()const {
	return this->productName;
}

void Furniture::setStockAmount(int stockAmount) {
	this->stockAmount = stockAmount;
}
int Furniture::getStockAmount()const {
	return this->stockAmount;
}

string Furniture::toString()const {
	stringstream convertor;
	convertor << "article:" << this->articleNum << ", " << "product:" << this->productName << ", " << "stockAmount:" << this->stockAmount << toStringSpec();

	return convertor.str();
}
string Furniture::toString()const {

}