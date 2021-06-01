/**
* Solution to homework assignment 4
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Lubomir Stoykov
* @idnumber 62569
* @task 1
* @compiler VC
*/


#pragma once
#pragma warning(disable : 26812)

#include<string>
#include<iostream>
#include<sstream>

class Card {
public:

	enum category {
		monster,
		magic,
		pendulum
	};


	Card(const std::string& _name = "Unknown", const std::string& _effect = "Unknown", const unsigned _rarity = 0);
	virtual ~Card() = default;

	std::string getName() const;
	std::string getEffect() const;
	unsigned getRarity() const;
	category getCategory() const;

	void setName(const std::string&);
	void setEffect(const std::string&);
	void setRarity(const unsigned);

	bool operator>(const Card&) const;
	bool operator<(const Card&) const;

	virtual std::ostringstream stringOutput() const = 0;
	void print() const;
	virtual Card* copy() const = 0;

protected:
	std::string name;
	std::string effect;
	unsigned rarity;
	category CATEGORY;
};


