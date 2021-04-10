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

#include"Libraries_Enums.hpp"

class Money 
{
public:

	

	Money(const unsigned int qg = 0, const unsigned int qs = 0);

	unsigned int getGold() const;
	unsigned int getSilver() const;
	
	bool addItem(const unsigned int, const Type); //adds only one type of currency

	bool addItem(const unsigned int, const unsigned int); //adds to both types of currency in order gold,silver

	bool deleteItem(const unsigned int, const Type);

	unsigned int SlotsNeeded() const;
	void EraseItem();

	std::string print() const;

private:
	unsigned int money[2] = {};

	void RestackMoney();
};