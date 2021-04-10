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

#include"Armor.hpp"
#include"Weapon.hpp"

#pragma warning(disable:26812)

template<typename T>
class Equipment
{
public:
	
	Equipment() = default;
	Equipment(const Equipment<T>&);
	Equipment<T>& operator=(const Equipment<T>&);

	bool operator==(const Equipment<T>&);
	bool operator!=(const Equipment<T>&);

	bool isFull() const;
	bool isEmpty() const;

	void EraseEquipment();
	bool addItem(const TypeAW, const unsigned int, const unsigned int dummy1 = 0,
		const WeaponCategory dummy2 = unknown_cat);//added dummies for using the same name in Armor and Weapon
	bool addItem(const T&);
	bool removeItem(const unsigned int);

	T BestEquipment() const;

	unsigned int getSlots() const;

	std::string print() const;

private:

	std::vector<T> Items;
	const unsigned int slots = 24;
	unsigned int used_slots = 0;
};


template<typename T>
Equipment<T>::Equipment(const Equipment<T>& other)
{
	Items = other.Items;
	used_slots = other.used_slots;
}

template<typename T>
Equipment<T>& Equipment<T>::operator=(const Equipment<T>& other)
{
	if (this != &other) {
		Items = other.Items;
		used_slots = other.used_slots;
	}
	return *this;
}

template<typename T>
bool Equipment<T>::operator==(const Equipment<T>& other)
{
	return this->BestEquipment()== other.BestEquipment();
}
template<typename T>
bool Equipment<T>::operator!=(const Equipment<T>& other)
{
	return !(this->BestEquipment() == other.BestEquipment());
}

template<typename T>
bool Equipment<T>::isFull() const
{
	return used_slots == slots;
}
template<typename T>
bool Equipment<T>::isEmpty() const
{
	return used_slots == 0;
}
template<typename T>
void Equipment<T>::EraseEquipment()
{
	Items.clear();
	used_slots = 0;
}
template<typename T>
bool Equipment<T>::addItem(const TypeAW type, const unsigned int num, const unsigned int num2,
	const WeaponCategory type2)
{
	T tmp(type, num, num2, type2);
	if (used_slots + tmp.SlotsNeeded() <= slots) {
		Items.push_back(tmp);
		used_slots += tmp.SlotsNeeded();
		return 1;
	}
	return 0;
}

template<typename T>
bool Equipment<T>::addItem(const T& Item)
{
	if (used_slots + Item.SlotsNeeded() <= slots) {
		Items.push_back(Item);
		used_slots += Item.SlotsNeeded();
		return 1;
	}
	return 0;
}

template<typename T>
bool Equipment<T>::removeItem(const unsigned int index)
{
	if (index < Items.size()) {
		used_slots -= Items[index].SlotsNeeded();
		Items.erase(Items.begin() + index);
		Items.shrink_to_fit();
		return 1;
	}
	return 0;
}

template<typename T>
T Equipment<T>::BestEquipment() const
{

	if (Items.size() != 0) {

		std::vector<double> tmp;
		for (size_t i = 0; i < Items.size(); i++) {
			tmp.push_back(Items[i].getScore());
		}
		int best = 0;
		for (size_t i = 0; i < tmp.size(); i++) {
			if (tmp[i] > tmp[best]) {
				best = i;
			}
		}
		return Items[best];
	}
	std::cout << "No items in equipment! Returning default equipment." << std::endl;
	T tmp = T();
	return tmp;
}

template<typename T>
unsigned int Equipment<T>::getSlots() const
{
	return used_slots;
}

template<typename T>
std::string Equipment<T>::print() const
{
	std::string tmp{ "This Inventory of type Equipment has " + std::to_string(Items.size()) + " items:" };
	for (size_t i = 0; i < Items.size(); i++) {
		tmp += "\n--> "+Items[i].print();
	}
	tmp += "\nwhich take in total: " + std::to_string(used_slots) + " slots.\n";
	return tmp;
}