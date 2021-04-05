#include"Materials.hpp"

//Materials::Materials()
//{
//	for (int i = 0; i < 4; i++) {
//		QuantityByType[i] = 0;
//	}
//}

void Materials::addItem(const Type type, const unsigned int quantity)
{
	QuantityByType[type] += quantity;
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