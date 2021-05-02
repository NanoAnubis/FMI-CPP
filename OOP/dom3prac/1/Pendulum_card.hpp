/**
* Solution to homework assignment 3
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
#include"Monster_card.hpp"
#include"Magic_card.hpp"

class PendulumCard : public MonsterCard, public MagicCard
{
public:

	PendulumCard(const std::string& name = "Unknown", const std::string& effect = "Unknown", 
		const unsigned int attack = 0, const unsigned int deffence = 0, const Type& type = unknown, const unsigned int scale = 1);

	int getScale() const;

	void setScale(const unsigned int);

private:

	unsigned int scale;
};