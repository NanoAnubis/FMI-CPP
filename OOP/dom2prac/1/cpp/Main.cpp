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

#include"Inventory.hpp"


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
	mon1.print();
	mon2.print();
	
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
	
	Armor a1;
	Armor a2(cloth_a,6);
	a1.setType(leather);
	a1.setDefence(10);
	a2.addEffect("Protection", 15);
	a2.addEffect("Protection", 15);
	a2.addEffect("Thoughness", 10);
	a2.addEffect("aaa", 5);
	a2.removeEffect("aaa");
	//std::cout << (a1 != a2) << std::endl;
	
	Weapon w1;
	Weapon w2(one_handed, 30, 50, sword);
	w2.ChangeType(two_handed);
	w2.ChangeCategory(bow);
	w2.ChangeCategory(dagger);
	w2.addEffect("Sharpness", 3.2);
	w2.addEffect("Sharpness", 3.2);
	w2.addEffect("Sharpness", 8);
	w2.addEffect("AAA", 100.2);
	w2.ChangePowerOfEffect("AAA", 10.1);
	w2.removeEffect("AAA");
	//std::cout << (w1 == w2) << std::endl;


	Equipment<Weapon> eqW;
	Equipment<Armor> eqA;
	eqW.addItem(w2);
	eqA.addItem(a2);
	eqW.addItem(two_handed, 60, 90, mace);
	eqA.addItem(mail, 100);
	eqW.addItem(w1);
	eqA.addItem(a1);
	eqW.removeItem(5);
	eqA.removeItem(5);
	eqW.removeItem(2);
	eqA.removeItem(2);
	Equipment<Weapon> eqW2;
	eqW2 = eqW;
	eqW.BestEquipment();
	std::cout << (eqW2 == eqW) << std::endl;

	Inventory<Backpack<Money>> inv1;
	Inventory<Backpack<Materials>> inv2;
	Inventory<Equipment<Armor>> inv3;
	Inventory<Equipment<Weapon>> inv4;
	Inventory<Backpack<Money>> inv5(backmoney2);
	Inventory<Backpack<Materials>> inv6(backmat1);
	Inventory<Equipment<Armor>> inv7(eqA);
	Inventory<Equipment<Weapon>> inv8(eqW);

	//std::cout << inv5.getStorage().print();

	std::cout << inv5 << std::endl;
	std::cout << inv6 << std::endl;
	std::cout << inv7 << std::endl;
	std::cout << inv8 << std::endl;
	return 0;
}