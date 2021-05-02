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


#include"Card.hpp"

Card::Card(const std::string& _name, const std::string& _effect)
{
	setName(_name);
	setEffect(_effect);
}

std::string Card::getName() const
{
	return name;
}

std::string Card::getEffect() const
{
	return effect;
}


void Card::setName(const std::string& newname)
{
	this->name = newname;
}

void Card::setEffect(const std::string& neweffect)
{

	this->effect = neweffect;
}
