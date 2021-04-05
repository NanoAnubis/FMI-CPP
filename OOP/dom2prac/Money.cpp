#include"Money.hpp"

Money::Money(const unsigned int qg, const unsigned int qs) // qg/gs = quantity gold/silver
{
	money[gold] = qg;
	money[silver] = qs;
	RestackMoney();
}

unsigned int Money::getGold() const
{
	return money[gold];
}
unsigned int Money::getSilver() const
{
	return money[silver];
}

void Money::TotalMoney() const
{
	std::cout << money[gold] << " gold " << money[silver] << " silver" << std::endl;
}

bool Money::addItem(const unsigned int quantity, const Type type)
{
	money[type] += quantity;
	RestackMoney();
	return 1;
}

bool Money::deleteItem(const unsigned int quantity, const Type type)
{	
	int tmp = money[type] - quantity;
	if (type == gold && tmp < 0)
	{
		std::cout << "There isn't that much gold to be removed!" << std::endl;
		return 0;
	}
	else if (tmp < 0) {
		while (money[gold] > 0 && tmp < 0) {
			money[gold]--;
			money[silver] += 100;
			tmp = money[silver] - quantity;
		}
		if (tmp < 0) {
			std::cout << "There isn't that much money to be removed!" << std::endl;
			RestackMoney();
			return 0;
		}
		money[silver] -= quantity;
		RestackMoney();
		return 1;
	}

	money[type] -= quantity;
	return 1;
}

bool Money::addItem(const unsigned int quantityG, const unsigned int quantityS)
{
	money[gold] += quantityG;
	money[silver] += quantityS;
	RestackMoney();
	return 1;
}

unsigned int Money::SlotsNeeded() const
{
	return 0;
}

void Money::EraseItem()
{
	money[gold] = 0;
	money[silver] = 0;
}

void Money::RestackMoney()
{
	while (money[silver] >= 100) {
		money[silver] -= 100;
		money[gold] += 1;
	}
}