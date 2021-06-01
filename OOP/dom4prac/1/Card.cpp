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


#include"Card.hpp"

Card::Card(const std::string& _name, const std::string& _effect, const unsigned _rarity)
{
	setName(_name);
	setEffect(_effect);
	setRarity(_rarity);
}

std::string Card::getName() const
{
	return name;
}

std::string Card::getEffect() const
{
	return effect;
}

unsigned Card::getRarity() const
{
	return rarity;
}

Card::category Card::getCategory() const
{
	return Card::CATEGORY;
}

void Card::setName(const std::string& newname)
{
	this->name = newname;
}

void Card::setEffect(const std::string& neweffect)
{

	this->effect = neweffect;
}

void Card::setRarity(const unsigned newrarity)
{
	this->rarity = newrarity;
}

bool Card::operator>(const Card& other) const
{
	return (rarity > other.rarity);
}
bool Card::operator<(const Card& other) const
{
	return (rarity < other.rarity);
}

void Card::print() const
{
	std::cout << this->stringOutput().str();;
}

//a