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

class Weapon
{
public:

	Weapon(const TypeAW type = unknown, const unsigned int mindmg = 0, const unsigned int maxdmg = 0, 
		const WeaponCategory category = unknown_cat);
	bool operator==(const Weapon&) const;
	bool operator!=(const Weapon&) const;

	bool ChangeType(const TypeAW);
	bool ChangeCategory(const WeaponCategory);
	bool addEffect(const std::string,const double);
	bool removeEffect(const std::string);
	bool ChangePowerOfEffect(const std::string, const double);

	double getScore() const;
	unsigned int SlotsNeeded() const;

	std::string print() const;

private:

	TypeAW type;
	WeaponCategory category;
	//std::string WeapCategory;
	unsigned int hit_damage[2];
	std::vector<std::string> Effects_name;
	std::vector<double> Effects_power;
	double Weaponscore = 0;

	void setWeaponScore();
};

