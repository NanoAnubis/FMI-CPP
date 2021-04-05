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

void Money::addItem(const unsigned int quantity, const Type type)
{
	money[type] += quantity;
	RestackMoney();
}
void Money::addItem(const unsigned int quantityG, const unsigned int quantityS)
{
	money[gold] += quantityG;
	money[silver] += quantityS;
	RestackMoney();
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