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


#include"Monster_card.hpp"

MonsterCard::MonsterCard(const std::string& _name, const std::string& _effect, 
	unsigned _rarity, const unsigned int _attack_points, const unsigned int _defence_points) 
	: Card(_name,_effect,_rarity)
{
	setAttack(_attack_points);
	setDefence(_defence_points);
	CATEGORY = monster;
}

unsigned MonsterCard::getAttack() const
{
	return attack_points;
}

unsigned MonsterCard::getDefence() const
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

std::ostringstream MonsterCard::stringOutput() const
{
	std::ostringstream s;
	s << this->getName() << "|" << this->getEffect() << "|" << this->getRarity()
		<< "|" << this->getAttack() << "|" << this->getDefence() << std::endl;
	return s;
}

Card* MonsterCard::copy() const
{
	return new MonsterCard(*this);
}