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

#include"Weapon.hpp"
#pragma warning(disable:26812)

Weapon::Weapon(const TypeAW type, const unsigned int mindmg, 
	const unsigned int maxdmg, const WeaponCategory category)
{
	this->type = type;
	this->category = category;
	hit_damage[0] = mindmg;
	hit_damage[1] = maxdmg;
	Weaponscore = 0;
	setWeaponScore();
}
bool Weapon::operator==(const Weapon& other) const
{
	return this->Weaponscore == other.getScore();
}
bool Weapon::operator!=(const Weapon& other) const
{
	return !(this->Weaponscore == other.getScore());
}

bool Weapon::ChangeType(const TypeAW _type)
{
	if (category < 0 || _type == category/10) {
		type = _type;
		;
		return 1;
	}
	std::cout << "Weapon can't be of this type! Check category first." << std::endl;
	return 0;
}
bool Weapon::ChangeCategory(const WeaponCategory name)
{
	if (name < 0 || name/10 == type) {
		category = name;
		return 1;
	}
	std::cout << "Weapon can't be of this category! Check type first." << std::endl;
	return 0;
}

bool Weapon::addEffect(const std::string name, const double power)
{
	if (power < 0) {
		std::cout << "Power can't be negative!" << std::endl;
		return 0;
	}

	for (size_t i = 0; i < Effects_name.size(); i++) {
		if (Effects_name[i] == name) {
			if (Effects_power[i] < power) {
				Effects_power[i] = power;
				setWeaponScore();
				return 1;
			}
			else return 0;
		}
	}
	Effects_name.push_back(name);
	Effects_power.push_back(power);
	setWeaponScore();
	return 1;
}
bool Weapon::removeEffect(const std::string name)
{
	for (size_t i = 0; i < Effects_name.size(); i++) {
		if (Effects_name[i] == name) {

			Effects_name.erase(Effects_name.begin() + i);
			Effects_name.shrink_to_fit();
			Effects_power.erase(Effects_power.begin() + i);
			Effects_power.shrink_to_fit();

			setWeaponScore();
			return 1;
		}
	}
	return 0;
}
bool Weapon::ChangePowerOfEffect(const std::string name, const double power)
{
	if (power < 0) {
		std::cout << "Power can't be negative!" << std::endl;
		return 0;
	}
	for (size_t i = 0; i < Effects_name.size(); i++) {
		if (Effects_name[i] == name) {
			Effects_power[i] = power;
			setWeaponScore();
			return 1;
		}
	}
	return 0;

}

double Weapon::getScore() const
{
	return Weaponscore;
}

unsigned int Weapon::SlotsNeeded() const
{
	return type;
}

void Weapon::setWeaponScore()
{
	unsigned int tmp = hit_damage[0] + hit_damage[1];
	Weaponscore = (double)tmp/2.0;
	for (size_t i = 0; i < Effects_power.size(); i++) {
		Weaponscore += Effects_power[i];
	}

	switch (type)
	{
	case one_handed: {
		Weaponscore *= 0.75;
		break;
	}
		
	case two_handed: {
		Weaponscore *= 1.5;
		break;
	}
	default:
		Weaponscore = 0;
		break;
	}

}

std::string TypeWToString(TypeAW type)
{
	switch (type)
	{ 
	case one_handed:
		return "One-handed ";
	case two_handed:
		return "Two-handed ";
	default:
		return "unknown";
	}
}

std::string CategoryToString(WeaponCategory type)
{
	switch (type)
	{
	case unknown_cat:
		return "unknown";
	case axe:
		return "axe";
	case sword:
		return "sword";
	case dagger:
		return "dagger";
	case mace:
		return "mace";
	case staff:
		return "staff";
	case spear:
		return "spear";
	case bow:
		return "bow";
	case crossbow:
		return "crossbow";
	case lance:
		return "lance";
	default:
		return "unknown";
	}
}

std::string Weapon::print() const
{
	std::string tmp{ TypeWToString(type)+CategoryToString(category)+ " weapon with " + std::to_string(hit_damage[0]) +
		" min hit damage, "+ std::to_string(hit_damage[1]) +" max hit damage, has " +
		std::to_string(Weaponscore) + " weaponscore and these effects:" };
	for (size_t i = 0; i < Effects_name.size(); i++) {
		tmp += "\n\t-" + Effects_name[i] + " with " + std::to_string(Effects_power[i]) + " power";
	}
	tmp += "\n";
	return tmp;
}