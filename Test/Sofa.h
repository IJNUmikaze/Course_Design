#pragma once
#include "Furniture.h"
#include<string>
using namespace std;
class Sofa :
    public Furniture
{
public:
    Sofa(string articleNum = "146513", string productName = "Fs", int stockAmount = 54, int seatNum=3,string converType="leather"):Furniture(articleNum,productName,stockAmount),seatNum(seatNum),coverType(coverType){}
    virtual ~Sofa();
    string getCoverType()const;
    virtual string toStringSpec()const;
private:
    int seatNum;
    string coverType;
};

