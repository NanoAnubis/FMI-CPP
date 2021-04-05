#pragma once

#include <iostream>
//#include <vector>

//enum Type {
//	essence,	//0
//	herbs,		//1
//	ores,		//2
//	cloth		//3
//};

#include"TypeEnum.hpp"

class Materials
{
public:

	

	//Materials();
	bool addItem(const unsigned int, const Type);
	bool deleteItem(const unsigned int, const Type);
	unsigned int getQuantityByType(const Type) const;

	unsigned int SlotsNeeded() const;
	void EraseItem();

private:

	unsigned int QuantityByType[4] = {};
};
