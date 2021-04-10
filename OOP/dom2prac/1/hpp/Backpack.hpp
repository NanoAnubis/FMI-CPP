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

#include"Materials.hpp"
#include"Money.hpp"

#pragma warning(disable:26812)

template<typename T>
class Backpack
{
public:

	Backpack() = default;
	Backpack(const Backpack<T>&);
	Backpack<T>& operator=(const Backpack<T>&);

	Backpack(const T);

	bool isFull() const;
	bool isEmpty() const;

	void EraseBackpack();
	bool addItem(const unsigned int, const Type);
	bool removeItem(const unsigned int, const Type);

	unsigned int getSlots() const;

	std::string print() const;

private:
	
	T Item;
	unsigned int used_slots = 0;
	const unsigned int slots = 16;
	
};

template <typename T>
Backpack<T>::Backpack(const Backpack<T>& other)
{
	Item = other.Item;
	used_slots = other.used_slots;
}

template<typename T>
Backpack<T>& Backpack<T>::operator=(const Backpack<T>& other)
{
	if (this != &other) {
		Item = other.Item;
		used_slots = other.used_slots;
	}
	return *this;
}

template <typename T>
Backpack<T>::Backpack(const T other)
{
	if (other.SlotsNeeded() <= slots) {
		Item = other;
		used_slots = other.SlotsNeeded();
	}
}

template <typename T>
bool Backpack<T>::isFull() const
{
	return used_slots == 16;
}
template <typename T>
bool Backpack<T>::isEmpty() const
{
	return used_slots == 0;
}

template <typename T>
void Backpack<T>::EraseBackpack()
{
	Item.EraseItem();
	used_slots = 0;
}

template <typename T>
bool Backpack<T>::addItem(const unsigned int quantity, const Type type)
{
	if (Item.addItem(quantity, type) == true) {
		used_slots = Item.SlotsNeeded();
		return true;
	}
	return false;


}

template <typename T>
bool Backpack<T>::removeItem(const unsigned int quantity, const Type type)
{
	if (Item.deleteItem(quantity, type) == true) {
		used_slots = Item.SlotsNeeded();
		return true;
	}
	return false;
}

template<typename T>
unsigned int Backpack<T>::getSlots() const
{
	return used_slots;
}

template<typename T>
std::string Backpack<T>::print() const
{
	std::string tmp{ "This Inventory of type Backpack " + Item.print() + 
		"which take: " + std::to_string(used_slots) + " slots.\n" };

	return tmp;
}