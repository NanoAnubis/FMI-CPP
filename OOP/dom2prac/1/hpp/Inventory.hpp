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

#include"Backpack.hpp"
#include"Equipment.hpp"

template<typename T>
class Inventory
{
public:

	Inventory() = default;
	Inventory(const T);

	bool operator==(const Inventory<T>&);
	bool operator!=(const Inventory<T>&);

	friend std::ostream& operator<<(std::ostream& out, const Inventory& inventory)
	{
		return out << inventory.Storage.print();
	}

private:

	T Storage;

};

template<typename T>
Inventory<T>::Inventory(const T _storage)
{
	Storage = _storage;
}

template<typename T>
bool Inventory<T>::operator==(const Inventory<T>& other)
{
	return Storage.getSlots() == other.Storage.GetSlots();
}
template<typename T>
bool Inventory<T>::operator!=(const Inventory<T>& other)
{
	return !(Storage.getSlots() == other.Storage.GetSlots());
}
