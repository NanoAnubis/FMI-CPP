#include"Monster_card.hpp"
#include <cstring>
#include <iostream>

Monster_card::Monster_card()
{
	setName("Unknown");
	setAttack(0);
	setDefence(0);
	set_isEmpty(true);
}

Monster_card::Monster_card(const char* _name, const unsigned int _attack_points, const unsigned int _defence_points)
{
	setName(_name);
	setAttack(_attack_points);
	setDefence(_defence_points);
	set_isEmpty(false);
}

const char* Monster_card::getName() const
{
	return name;
}

int Monster_card::getAttack() const
{
	return attack_points;
}

int Monster_card::getDefence() const
{
	return defence_points;
}

bool Monster_card::get_isEmpty_monster() const
{
	return isEmpty;
}

void Monster_card::setName(const char* _name)
{
	if (strlen(_name) > 25) {
		std::cout << "ERROR : Too big monster name! ->" << _name << std::endl;
		char* newname = new char[26]{ "Error_with_assigning_name" };
		strcpy(name, newname);
		delete[] newname;
	}
	else strcpy(name, _name);
}

void Monster_card::setAttack(const unsigned int _attack_points)
{
	attack_points = _attack_points;
}

void Monster_card::setDefence(const unsigned int _defence_points)
{
	defence_points = _defence_points;
}

void Monster_card::set_isEmpty(const bool _isEmpty)
{
	isEmpty = _isEmpty;
}
