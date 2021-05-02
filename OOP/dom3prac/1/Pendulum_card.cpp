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


#include "Pendulum_card.hpp"


PendulumCard::PendulumCard(const std::string& name, const std::string& effect,
	const unsigned int attack, const unsigned int deffence, const Type& type, const unsigned int scale)
	: Card(name,effect),MagicCard(name,effect,type),MonsterCard(name,effect,attack,deffence)
{
	if (scale >= 1 && scale <= 13) {
		this->scale = scale;
	}
	else {
		std::cout << "Pendulum scale isn't in the possible range [1,13]! Set to default (1)." << std::endl;
		this->scale = 1;
	}

}

int PendulumCard::getScale() const
{
	return scale;
}

void PendulumCard::setScale(const unsigned int _scale)
{
	scale = _scale;
}