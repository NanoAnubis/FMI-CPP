#include<iostream>

#include"Backpack.hpp"

int main() {

	Materials m1;
	m1.addItem(50, herbs);
	m1.addItem(44, ores);
	m1.addItem(73, cloth);
	m1.addItem(12, essence);
	//std::cout << m1.getQuantityByType(Materials::ores) << std::endl;

	Money mon1;
	Money mon2(21, 66);
	mon1.addItem(2, gold);
	mon1.addItem(265, silver);
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

	backmoney2.addItem(30, silver);
	backmat1.addItem(66, ores);
	backmoney2.removeItem(2, gold);
	backmoney2.removeItem(500, silver);
	backmoney2.removeItem(200, gold);
	backmoney2.removeItem(50000, silver);
	backmat1.removeItem(100, ores);

	return 0;
}