#include "FurnitureContainer.h"
FurnitureContainer::FurnitureContainer(const FurnitureContainer& F) {
	this->objNumberInArray = F.objNumberInArray;
	Sofa* Sptr = nullptr;
	Table* Tptr = nullptr;
	for (int i = 0; i < this->objNumberInArray; i++) {
		Sptr = dynamic_cast<Sofa*>(F.furnitureArray[i]);//把基类指针转化为子类指针，如果成功则返回正常指针，不成功就返回空指针
		if (Sptr != nullptr) {
			this->furnitureArray[i] = new Sofa(*Sptr);
		}
		Tptr = dynamic_cast<Table*>(F.furnitureArray[i]);
		if (Tptr != nullptr) {
			this->furnitureArray[i] = new Table(*Tptr);
		}

		//this->furnitureArray[i] = new Furniture(*F.furnitureArray[i]);//?????????????????
	}
}

void FurnitureContainer::operator = (const FurnitureContainer& F) {
	furnitureArray[0]->getArticleNum() = F.furnitureArray[0]->getArticleNum();
}

void FurnitureContainer::SofaAdd(string articleNum, string product, int stockNum) {
	this->furnitureArray[objNumberInArray++] = new Sofa(articleNum, stockNum);
}

void FurnitureContainer::removeFurniture(string articleNum) {
	int i = 0;
	while (i < this->objNumberInArray) {
		if (this->furnitureArray[i]->getArticleNum() == articleNum) {
			delete this->furnitureArray[i];
		}
		else {
			i++;
		}
	}
}