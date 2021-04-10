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

class Armor
{
public:

	Armor(const TypeAW type = unknown, const unsigned int defence = 0, 
		const int dummy1 = 0, const WeaponCategory dummy2 = unknown_cat);//last two are dummy values for template
	bool operator==(const Armor&) const;
	bool operator!=(const Armor&) const;

	bool addEffect(const std::string, const double);
	bool removeEffect(const std::string);

	void setType(const TypeAW);
	void setDefence(const unsigned int);

	double getScore() const;
	unsigned int SlotsNeeded() const;

	std::string print() const;

private:

	TypeAW type;
	unsigned int defence;
	std::vector<std::string> Effects_name;
	std::vector<double> Effects_power;
	double gearscore;

	void setGearscore();
};