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
#pragma warning(disable : 4996)

#include"Card.hpp"
//#include <cstring>
//#include <iostream>

class MonsterCard : virtual public Card
{
public:

	MonsterCard(const std::string& _name = "Unknown", const std::string& _effect= "Unknown",
		const unsigned _rarity = 0,	const unsigned int att = 0, const unsigned int def = 0);

	unsigned getAttack() const;
	unsigned getDefence() const;

	void setAttack(const unsigned int);
	void setDefence(const unsigned int);

	std::ostringstream stringOutput() const override;
	virtual Card* copy() const override;

private:

	unsigned int attack_points;
	unsigned int defence_points;
};
