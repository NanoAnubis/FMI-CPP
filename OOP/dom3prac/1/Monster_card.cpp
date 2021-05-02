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


#include"Monster_card.hpp"

MonsterCard::MonsterCard(const std::string& _name, const std::string& _effect, 
	const unsigned int _attack_points, const unsigned int _defence_points) 
	: Card(_name,_effect)
{
	setAttack(_attack_points);
	setDefence(_defence_points);
}

int MonsterCard::getAttack() const
{
	return attack_points;
}

int MonsterCard::getDefence() const
{
	return defence_points;
}

void MonsterCard::setAttack(const unsigned int _attack_points)
{
	attack_points = _attack_points;
}

void MonsterCard::setDefence(const unsigned int _defence_points)
{
	defence_points = _defence_points;
}
