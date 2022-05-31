#pragma once
#include"Furniture.h"
#include"Sofa.h"
#include"Table.h"
#include<string>
using namespace std;
class FurnitureContainer
{
public:
	FurnitureContainer();
	virtual ~FurnitureContainer();
	FurnitureContainer(const FurnitureContainer& F);
	void operator =(const FurnitureContainer& F);
	void SofaAdd(string articleNum, string product, int stockNum);
	void removeFurniture(string articleNum);
private:
	static const int Capacity = 30;
	Furniture* furnitureArray[Capacity];
	//Furniture** furnitureArray;
	int objNumberInArray;
};

