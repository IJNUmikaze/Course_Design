#include "Sofa.h"
#include<sstream>
string Sofa::getCoverType()const {
	return this->coverType;
}

string Sofa::toStringSpec()const {
	stringstream convertor;
	convertor << "seatNum:" << this->seatNum << ", " << "coverType:" << this->coverType;
	return convertor.str();
}