#pragma once
#include<iostream>

class Money 
{
public:

	enum Type {
		gold,	//0
		silver	//1
	};

	Money(const unsigned int qg = 0, const unsigned int qs = 0);

	unsigned int getGold() const;
	unsigned int getSilver() const;
	void TotalMoney() const;
	
	void addItem(const unsigned int, const Type); //adds only one type of currency
	void addItem(const unsigned int, const unsigned int); //adds to both types of currency in order gold,silver

	unsigned int SlotsNeeded() const;
	void EraseItem();
private:
	unsigned int money[2] = {};

	void RestackMoney();
};