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


#include "Pendulum_card.hpp"



PendulumCard::PendulumCard(const std::string& name, const std::string& effect, const unsigned rarity,
	const unsigned int attack, const unsigned int deffence, const unsigned int scale, const Type& type)
	: Card(name,effect, rarity),MagicCard(name,effect,rarity,type),MonsterCard(name,effect,rarity,attack,deffence)
{
	if (scale >= 1 && scale <= 13) {
		this->scale = scale;
	}
	else {
		std::cout << "Pendulum scale isn't in the possible range [1,13]! Set to default (1)." << std::endl;
		this->scale = 1;
	}
	CATEGORY = pendulum;
}

unsigned PendulumCard::getScale() const
{
	return scale;
}

void PendulumCard::setScale(const unsigned int _scale)
{
	scale = _scale;
}

std::string Enumts2(const Type type) {
	switch (type)
	{
	case 1: return "trap";
	case 2: return "buff";
	case 3: return "spell";
	default:
		return "unknown";
	}
}


std::ostringstream PendulumCard::stringOutput() const
{
	std::ostringstream s;
	s << this->getName() << "|" << this->getEffect() << "|" << this->getRarity()
		<< "|" << this->getAttack() << "|" << this->getDefence() << "|" << this->getScale() 
		<< "|" <<Enumts2(this->getType()) << std::endl;
	return s;
}

Card* PendulumCard::copy() const
{
	return new PendulumCard(*this);
}