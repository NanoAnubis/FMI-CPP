#pragma once

//#include <iostream>
#include <vector>

class Materials
{
public:
	enum Type {
		essence,	//0
		herbs,		//1
		ores,		//2
		cloth		//3
	};

	//Materials();
	void addItem(const Type, const unsigned int);
	unsigned int getQuantityByType(const Type) const;

	unsigned int SlotsNeeded() const;
	void EraseItem();

private:

	unsigned int QuantityByType[4] = {};
};
