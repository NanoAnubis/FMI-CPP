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

#include"Materials.hpp"
#pragma warning(disable:26812)

Materials::Materials(const unsigned int e, const unsigned int h, const unsigned int o, const unsigned int c)
{
	QuantityByType[e] = e;
	QuantityByType[h] = h;
	QuantityByType[o] = o;
	QuantityByType[c] = c;
}

bool Materials::addItem(const unsigned int quantity, const Type type)
{
	QuantityByType[type] += quantity;
	if (SlotsNeeded() > 16) {
		QuantityByType[type] -= quantity;
		std::cout << "Not enough space!" << std::endl;
		return 0;
	}
	return 1;
}

bool Materials::deleteItem(const unsigned int quantity, const Type type)
{
	int tmp = QuantityByType[type] - quantity;
	if (tmp < 0) {
		std::cout << "There aren't so many materials of given type to be removed!" << std::endl;
		return 0;
	}
	QuantityByType[type] -= quantity;
	return 1;
}

unsigned int Materials::getQuantityByType(const Type type) const
{
	return QuantityByType[type];
}

unsigned int Materials::SlotsNeeded() const
{
	int slots = 0;

	slots += QuantityByType[essence] / 10;
	if (QuantityByType[essence] % 10 != 0) slots++;
	for (int i = 1; i < 4; i++) {
		slots += QuantityByType[i] / 20;
		if (QuantityByType[i] % 20 != 0) slots++;
	}

	return slots;
}

void Materials::EraseItem()
{
	for (int i = 0; i < 4; i++) {
		QuantityByType[i] = 0;
	}
}

std::string Materials::print() const
{
	std::string tmp{ "of type Materials has:\n--> " + 
		std::to_string(QuantityByType[essence]) + " essences\n--> " +
		std::to_string(QuantityByType[herbs]) + " herbs\n--> " +
		std::to_string(QuantityByType[ores]) + " ores\n--> " +
		std::to_string(QuantityByType[cloth]) + " clothes\n" };

	return tmp;
}