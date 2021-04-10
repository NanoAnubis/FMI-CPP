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

#include"Armor.hpp"
#pragma warning(disable:26812)

Armor::Armor(const TypeAW type, const unsigned int defence, const int dummy1, const WeaponCategory dummy2)
{
	setType(type);
	setDefence(defence);
	//setGearscore();
}

bool Armor::operator==(const Armor& other) const
{
	return gearscore == other.getScore();
}
bool Armor::operator!=(const Armor& other) const
{
	return !(gearscore == other.getScore());
}

bool Armor::addEffect(const std::string name, const double power)
{
	if (power < 0) {
		std::cout << "Power can't be negative!" << std::endl;
		return 0;
	}

	for (size_t i = 0; i < Effects_name.size(); i++) {
		if (Effects_name[i] == name) {
			if (Effects_power[i] < power) {
				Effects_power[i] = power;
				return 1;
			}
			else return 0;
		}
	}
	Effects_name.push_back(name);
	Effects_power.push_back(power);
	setGearscore();
	return 1;
}
bool Armor::removeEffect(const std::string name)
{
	for (size_t i = 0; i < Effects_name.size(); i++) {
		if (Effects_name[i] == name) {

			Effects_name.erase(Effects_name.begin() + i);
			Effects_name.shrink_to_fit();
			Effects_power.erase(Effects_power.begin() + i);
			Effects_power.shrink_to_fit();

			setGearscore();
			return 1;
		}
	}
	return 0;
}

void Armor::setType(const TypeAW _type)
{
	type = _type;
}
void Armor::setDefence(const unsigned int _defence)
{
	defence = _defence;
}

double Armor::getScore() const
{
	return gearscore;
}

unsigned int Armor::SlotsNeeded() const
{
	return 1;
}

void Armor::setGearscore()
{
	gearscore = 0;
	for (size_t i = 0; i < Effects_power.size(); i++) {
		gearscore += Effects_power[i];
	}
}

std::string TypeAToString(TypeAW type)
{
	switch (type)
	{
	case unknown:
		return "Unknown";
	case cloth_a:
		return "Cloth";
	case leather:
		return "Leather";
	case mail:
		return "Mail";
	default:
		return "unknown";
	}
}

std::string Armor::print() const
{
	std::string tmp{ TypeAToString(type) + " armor with " + std::to_string(defence) +
		" defence, has " + std::to_string(gearscore) + " gearscore and these effects:" };
	for (size_t i = 0; i < Effects_name.size(); i++) {
		tmp += "\n\t-" + Effects_name[i] + " with " + std::to_string(Effects_power[i]) + " power";
	}
	tmp += "\n";
	return tmp;
}