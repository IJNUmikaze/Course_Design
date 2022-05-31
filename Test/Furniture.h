#pragma once
#include<string>
using namespace std;
class Furniture
{
public:
	Furniture(string articleNum = "65465", string productName = "B S", int stockAmount = 4);
	virtual ~Furniture();
	void setArticleNum(string articleNum);
	string getArticleNum()const;

	void setProductName(string productName);
	string getProductName()const;

	void setStockAmount(int stockAmount);
	int getStockAmount()const;

	string toString()const;
	virtual string toStringSpec()const;
private:
	string articleNum;
	string productName;
	int stockAmount;
};

