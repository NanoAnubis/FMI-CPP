#include"Materials.hpp"

//Materials::Materials()
//{
//	for (int i = 0; i < 4; i++) {
//		QuantityByType[i] = 0;
//	}
//}

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