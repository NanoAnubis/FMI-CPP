/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author Lubomir Stoykov
* @idnumber 62569
* @task 1
* @compiler VC
*/

#pragma once

#include"Libraries_Enums.hpp"

class Materials
{
public:

	Materials(const unsigned int e = 0, const unsigned int h = 0, const unsigned int o = 0, const unsigned int c = 0);
	
	bool addItem(const unsigned int, const Type);
	bool deleteItem(const unsigned int, const Type);
	unsigned int getQuantityByType(const Type) const;

	unsigned int SlotsNeeded() const;
	void EraseItem();

	std::string print() const;
private:

	unsigned int QuantityByType[4] = {};
};
