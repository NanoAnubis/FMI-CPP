#include<iostream>

#include"Backpack.hpp"

int main() {

	Materials m1;
	m1.addItem(Materials::herbs, 50);
	m1.addItem(Materials::ores, 44);
	m1.addItem(Materials::cloth, 73);
	m1.addItem(Materials::essence, 12);
	//std::cout << m1.getQuantityByType(Materials::ores) << std::endl;

	Money mon1;
	Money mon2(21, 66);
	mon1.addItem(2, Money::gold);
	mon1.addItem(265, Money::silver);
	mon2.addItem(33, 455);
	mon1.TotalMoney();
	mon2.TotalMoney();

	Backpack<Money> backmoney1;
	Backpack<Materials> backmat1;
	Backpack<Money> backmoney2(mon2);
	Backpack<Materials> backmat2(m1);

	std::cout << backmat2.isFull() << std::endl;
	std::cout << backmat2.isEmpty() << std::endl;
	backmat2.EraseBackpack();
	std::cout << backmat2.isEmpty() << std::endl;

	return 0;
}